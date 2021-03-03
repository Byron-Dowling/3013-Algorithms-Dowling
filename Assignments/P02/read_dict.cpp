/*
    Author:           Byron Dowling
    Email:            byrondowling7@gmail.com
    Label:            P02
    Title:            Processing in Linear Time/Getching
    Course:           3013
    Semester:         Spring 2021

    Description:
        Program loads up a linked list with dictionary words and using 
        getching, will allow the user to search for words. The program
        will capture the users input and provide the top results and a 
        number of total results found. Each serach query is time using the 
        Timer class.

    Usage:
        Simulates auto suggestion that is predominant in search engines such
        as Google and others (obviously on a much smaller scale). 

    Files:
        read_dict.cpp
        Timer.hpp
        mygetch.hpp
        Words.txt
*/

#include <iostream>
#include <time.h>
#include <chrono> 
#include "Timer.hpp"
#include "mygetch.hpp"
#include <string>
#include <vector>
#include <fstream>

using namespace std;


/*
    Struct Name: wordNode
 
    Description:
        A node that holds a string for a dictionary
  	    word and a pointer to the next wordNode
 
    Public Methods:
 	    string 					word
 	    wordNode* 			    Next
 
    Private Methods:
        None
 
    Usage:
  	    - Creates node for a Linked List
 
 */

struct wordNode
{
    wordNode* Next;
    string word;

    wordNode()
    {
        Next = NULL;
        word = "";
    }

};


/*
    Class Name: LinkedList
 
    Description:
        This class implements a simple Linked List consisting of wordNodes.
        The class has both Head and Tail wordNode pointers and a Size variable
        to keep track of the size of the list. This will serve as the basis for
        how we load up our dictionary words to be utilized later.
 
    Public Methods:
        - LinkedList() - default constructor
 	    - int Get_Size()
 	    - void Insert_Data(wordNode* entry)
 	    - vector<string> Find(string typed)
 	    - void Print()
 
    Private Methods:
        - No Private or Protected methods
 
    Usage:
        - Load up a linked list of wordNodes holding dicitonary words
 	    - Hold the dictionary data for traversing and searching
 	    - Print the results
 */

class LinkedList
{
protected:
    wordNode* Head;
    wordNode* Tail;
    int Size;


public:

 /*
    Constructor : LinkedList
 
    Description:
        loads private/protected variables 
        with default values.
 
    Params:
        None
 
    Returns:
        None
 */
    LinkedList()
    {
        Head = NULL;
        Tail = NULL;
        Size = 0;
    }


 /*
    Public : Get_Size()
 
    Description:
        Method returns the size of
        the Linked List.
 
    Params:
        None/Member Variables
 
    Returns:
        integer variable
 */
    int Get_Size()
    {
        return Size;
    }


/*
   Public : Insert_Data(wordNode* entry)

   Description:
       Method receives a wordNode and it is
       then loaded into the linked list. Since we
       are working with a sorted dictionary list, this is a
       simple end_sert and there is no need for front or 
       middle insertion methods.

   Params:
       wordNode* entry

   Returns:
       None
*/
    void Insert_Data(wordNode* entry)
    {
        if (!Head)
        {
            Head = Tail = entry;
        }

        else
        {
            Tail->Next = entry;
            Tail = entry;
        }

        Size++;
    }


/*
   Public : Print()

   Description:
       Method prints the results of the Linked List. It
       is not essential to the program's directive but I
       left it here as a sanity check to ensure the Data
       was loaded correctly and that the List was not empty.

   Params:
       None/Member Variables

   Returns:
       None
*/
    void Print() {
        // Always copy head so you don't destroy the list
        wordNode* Current = Head;

        // Standard traversal
        // Start at head and then goto next node.
        while (Current) {
            // loop fails when Current == NULL (which is 0)
            cout << Current->word;   // print name in node
            cout << endl;
            //cout << "->";                 // awesome graphics
            Current = Current->Next;    // goto next node
        }
        // End of list points to NULL
        cout << "NULL" << endl;
    }


/*
    Public : Find(string typed)

    Description:
        This method receives the typed/getched input from the user
        and cross-references it with the dictionary data and looks for
        matches. If a match is found, it is pushed to the Vector Results
        which is then returned at the end of the method. This is achieved
        using the substring and length of string functions to ensure that 
        only matches that share the same letters at the beginning of the word
        will count towards the Results.

    Params:
        string typed

    Returns:
        vector<string> Results
*/
   vector<string> Find(string typed)
    {

       vector<string> Results;


       wordNode* Current = Head;
        
       while (Current)
       {
            string found = "";


            found = Current->word;              // Temp variable for the word of the current wordNode stored

            int len = typed.length();           // length variable for the length of the word typed/passed in


            if (found.substr(0, len) == typed)  // if the length of the word from index 0 to the length of the
            {                                   // typed word is equal then it is pushed to Results
                Results.push_back(found);
            }

            Current = Current->Next;            // traverse to next wordNode
       }

        return Results;                         // return the vector of results
    }

};

int main() 
{
    LinkedList L1;                  // Linked List object
    vector<string> Dictionary;      // Placeholder Dictionary to read in the words.txt data

    ifstream in;
    in.open("Words.txt");


    Timer T1000;                    // Timer object and Terminator 2 Judgement Day reference
    T1000.Start();                  // Timing how long it takes to read and load the data

    while (!in.eof())               // Reading in the dictionary words
    {
        string Temp;

        in >> Temp;

        Dictionary.push_back(Temp);
    }

    T1000.End();

    cout << T1000.Seconds() << " seconds to read in the data." << endl;


    // Time to load the words into the Linked List
    Timer T2;

    T2.Start();

    /*
        Looping through the vector of dictionary words and allocating new wordNodes
        to hold a word and inserting them into our Linked List.
    */
    for (int j = 0; j < Dictionary.size(); j++) 
    {
        wordNode* Temp = new wordNode;

        string item = Dictionary[j];

        Temp->word = item;

        L1.Insert_Data(Temp);
    }

    T2.End();


    cout << T2.Seconds() << " seconds to read in the data." << endl;


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
       Matches = L1.Find(word);
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