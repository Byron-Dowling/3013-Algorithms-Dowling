## Program 4 - P04 - Processing in Trie Tree Time
### Byron Dowling
### Description:

This project is about loading a Prefix Tree with dictionary words, then timing how it takes to look them up. This program has a noticeable speed increase on finding word matches compared to our Linked List Linear Time implementation. When running on my machine, each search in linear time of the Linked List took around 0.05 seconds per search. However with our Prefix Tree, the initial search time for the first result was slightly quicker at around 0.04 seconds. Additionally, each search thereafter became even quicker as the log search time was fulfilled. 

### Files

|   #   | File                    | Description                                        |
| :---: | ----------------------- | -------------------------------------------------- |
|   1   | AA_P04.cpp              | Main driver of my project                          |
|   2   | Timer.hpp               | HPP File with Class Definition for Timing          |
|   3   | mygetch.hpp             | Getching Implementation/Helper file                |
|   4   | Words.txt               | text file of dictionary words                      |

### Instructions

- The program can be run from your machine's console or from this replit project: https://replit.com/join/njdbfmme-byrondowling
- The program expects an input text file of dictionary words which is provided in this repo
- Once the program launches and the Prefix Tree is loaded, the user simply types on the keyboard to start searching for word matches
- The getching portion of the program will capture the user input despite not displaying within the terminal
- If you mistype a letter, simply hit the backspace and the terminal will recognize and revert back to the previous iteration
- Hit Shift - Z to terminate the program.

### Example Input

![image of SS1](https://github.com/Byron-Dowling/3013-Algorithms-Dowling/blob/main/Assignments/P02/3013%20P02%20SS1.png?raw=true)

![image of SS2](https://github.com/Byron-Dowling/3013-Algorithms-Dowling/blob/main/Assignments/P02/3013%20P02%20SS2.png?raw=true)

![image of SS3](https://github.com/Byron-Dowling/3013-Algorithms-Dowling/blob/main/Assignments/P02/3013%20P02%20SS3.png?raw=true)

![image of SS4](https://github.com/Byron-Dowling/3013-Algorithms-Dowling/blob/main/Assignments/P02/3013%20P02%20SS4.png?raw=true)
