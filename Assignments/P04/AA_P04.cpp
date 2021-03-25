/*
    Author:           Byron Dowling
    Email:            byrondowling7@gmail.com
    Label:            P02
    Title:            Processing in Trie Tree Time/Getching
    Course:           3013
    Semester:         Spring 2021

    Description:
        Program loads up a Prefix Tree with dictionary words and using
        getching, will allow the user to search for words. The program
        will capture the users input and provide the top results and a
        number of total results found. Each serach query is time using the
        Timer class.

    Usage:
        Simulates auto suggestion that is predominant in search engines such
        as Google and others (obviously on a much smaller scale).

    Files:
        AA_P04.cpp
        Timer.hpp
        mygetch.hpp
        Words.txt
*/

#include <iostream>
#include "mygetch.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Timer.hpp"

using namespace std;

// Defining the character size of 26 for the alphabet
#define CHAR_SIZE 26


/*
    Struct Name: TrieNode

    Description:
        A node that holds a string for a dictionary
        word and a pointer to the next wordNode

    Public Methods:
        string 					Word
        TrieNode* 			    Character
        bool                    Leaf

    Private Methods:
        - None

    Usage:
        - Creates Trie Tree Node for a Prefix Tree

 */

struct TrieNode
{
    bool Leaf;
    string Word;
    TrieNode* Character[CHAR_SIZE];

    TrieNode()
    {
        Leaf = NULL;
        Word = "";

        for (int i = 0; i < CHAR_SIZE; i++)
        {
            this->Character[i] = nullptr;
        }
    }

};


/*
    Class Name: PrefixTree

    Description:
        This class implements a Prefix Tree consisting of TrieNodes.
        The class has a Root variable to keep track of the top of the
        tree as well as a vector of strings to return for our results.
        This will serve as the basis for how we load up our dictionary.

    Public Methods:
        - PrefixTree() - default constructor
        - void Insert_Data(string word)
        - vector<string> Find(string typed)

    Private/Protected Methods:
        - void Find(TrieNode* &Current, string typed)

    Usage:
        - Load up a Prefix Tree of TrieNodes holding dicitonary words
        - Hold the dictionary data for traversing and searching
        - Print the results
 */

class PrefixTree
{
protected:
    TrieNode* Root;
    vector<string> Search_Results;

    /*
    Protected : Find(Trieode* &Current, string typed)

    Description:
        This method receives the typed/getched input from the user
        and cross-references it with the dictionary data and looks for
        matches. The protected method Find is then called and is passed
        a TrieNode by reference as well as the getched input. If a match is
        found, it is pushed to the Vector Results data member which is then
        returned at the end of the method.

    Params:
        - TrieNode* &Current
        - string typed

    Returns:
        - None, Void
*/
    void Find(TrieNode* &Current, string typed)
    {
        if (Current->Leaf)
        {
            Search_Results.push_back(typed);
        }


        for (int i = 0; i < 26; i++)
        {
            if (Current->Character[i])
            {
                Find(Current->Character[i], typed + char(i + 65));
            }
        }
    }

public:

    /*
        Constructor : PrefixTree

        Description:
            Dynamically Allocates a 
            Root TriedNode.

        Params:
           - None

        Returns:
           - None
    */
    PrefixTree()
    {
        Root = new TrieNode;
    }


    /*
    Public : Insert_Data(string typed)

    Description:
        This method receives a string from the vector dictionary of words
        that is intialized in main. Each word is attached to a newly allocated
        TrieNode and is then inserted into the PrefixTree. Logic is written to
        determine whether the tree is empty or not before inserting.

    Params:
        - string typed

    Returns:
        - None, void
    */
    void Insert_Data(string word)
    {
        TrieNode* Current = Root;

        for (int i = 0; i < word.size(); i++)
        {
            if (Current->Character[word[i] - 65] == nullptr)
            {
                Current->Character[word[i] - 65] = new TrieNode();
            }

            Current = Current->Character[word[i] - 65];
        }

        Current->Leaf = true;
    }


    /*
        Public : Find(string typed)

        Description:
            This method receives the typed/getched input from the user
            and cross-references it with the dictionary data and looks for
            matches. The protected method Find is then called and is passed
            a TrieNode by reference as well as the getched input. If a match is 
            found, it is pushed to the Vector Results data member which is then 
            returned at the end of the method.

        Params:
            - string typed

        Returns:
            - vector<string> Results
    */
    vector<string> Find(string typed)
    {
        TrieNode* Current = Root;

        if (Search_Results.size() != 0)
        {
            Search_Results.clear();
        }

        for (int i = 0; i < typed.length(); i++)
        {
            Current = Current->Character[typed[i] - 65];
        }

        Find(Current, typed);
        return Search_Results;                         // return the vector of results
    }

};


int main()
{
    PrefixTree Lookup;
    vector<string> Dictionary;      // Placeholder Dictionary to read in the words.txt data

    ifstream in;
    in.open("Words.txt");


    Timer T1000;                    // Timer object
    T1000.Start();                  // Timing how long it takes to read and load the data

    while (!in.eof())               // Reading in the dictionary words
    {
        string Temp;

        in >> Temp;

        Dictionary.push_back(Temp);
    }

    T1000.End();

    cout << T1000.Seconds() << " seconds to read in the data." << endl;


    for (int z = 0; z < Dictionary.size(); z++)
    {
        string Temp = Dictionary[z];

        Lookup.Insert_Data(Temp);
    }



    char k;                 // holder for character being typed
    string word = "";       // var to concatenate letters to
    vector<string> Matches; // any matches found in vector of Dictionary Words

    string Top_Results[10];
    int SearchResults;

    cout << endl << "Type keys and watch what happens. Type capital Z to quit." << endl;

    // While capital Z is not typed keep looping
    while ((k = getch()) != 'Z')
    {

        // Tests for a backspace and if pressed deletes 
        // last letter from "word".
        if ((int)k == 127)
        {
            if (word.size() > 0)
            {
                word = word.substr(0, word.size() - 1);
            }
        }

        else
        {
            // Make sure a letter was pressed and only letter
            if (!isalpha(k))
            {
                cout << "Letters only!" << endl;
                continue;
            }

            // We know its a letter, lets make sure its lowercase.
            // Any letter with ascii value < 97 is capital so we
            // lower it.

            /*
                Reversed the ASCII values from starter code since my txt file is all
                capital letters, += 32 becomes -= 32, flipped < to > etc.
            */
            if ((int)k >= 97)
            {
                k -= 32;
            }
            word += k; // append char to word
        }


        Timer Auto_Suggestion;           // Timer for how long it takes to return word suggestions and total words found

        Auto_Suggestion.Start();
        Matches = Lookup.Find(word);
        Auto_Suggestion.End();

        SearchResults = Matches.size();


        if ((int)k != 32)
        { // if k is not a space print it
            cout << "Keypressed: " << k << " = " << (int)k << endl;
            cout << "Current Substr: " << word << endl;
            cout << SearchResults << " words found in " << Auto_Suggestion.Seconds() << " seconds" << endl;

            // This prints out the top ten results
            if (Matches.size() >= 10)
            {
                for (int i = 0; i < 10; i++)
                {
                    Top_Results[i] = Matches[i];
                    cout << Top_Results[i] << " ";
                }
            }

            else
            {
                for (int j = 0; j < Matches.size(); j++)
                {
                    Top_Results[j] = Matches[j];
                    cout << Top_Results[j] << " ";
                }
            }

            cout << endl << endl;
        }
    }

    return 0;
}