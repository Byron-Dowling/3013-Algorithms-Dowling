/*
    Author:           Byron Dowling
    Email:            byrondowling7@gmail.com
    Label:            05-P01
    Title:            Program 1 - Resizing the Stack
    Course:           3013
    Semester:         Spring 2021

    Description:
         Program creates an Array based stack by reading numbers from a file. 
         The number is adjudged to be even or odd and pushed to the stack if
         even and popped from the stack if odd. If the memory becomes too full
         or too empty, the stack size is adjusted accordingly.

    Usage:
         Can be used to implement an Array based stack that is conscious 
         about memory sized.

    Files:
         3013 Stack Main.cpp
         nums_test.txt
         nums.txt
         stacksample.txt
         StackP1_Results.txt

*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*
      ArrayStack

      Description:
           Array based stack

      Public Methods:
           - See class below

      Usage:
           - See main program

 */

class ArrayStack
{
private:
    int* A;           // pointer to array of int's
    int size;         // current max stack size
    int top;          // top of stack 
    int Max_Size;     // Max Size Variable
    float Ratio;      // Ratio of the Stack capacity
    int Resize;       // # of times resized

public:

    /*
           ArrayStack

           Description:
                Constructor no params

           Params:
              - None

           Returns:
              - NULL
     */

    ArrayStack() 
    {
        size = 10;
        A = new int[size];
        top = -1;
        Max_Size = 0;
        Ratio = 1;
        Resize = 0;
    }

    /*
          ArrayStack

          Description:
               Constructor size param

          Params:
              - int size

          Returns:
              - NULL
     */

    ArrayStack(int s) 
    {
        size = s;
        A = new int[s];
        top = -1;
        Max_Size = 0;
        Ratio = 1;
        Resize = 0;
    }

    /*
          Public bool: Empty

          Description:
               Stack empty?

          Params:
               NULL

          Returns:
               [bool] true = empty
     */

    bool Empty() 
    {
        return (top <= -1);
    }

    /*
          Public bool: Full

          Description:
               Stack full?

          Params:
               NULL

          Returns:
               [bool] true = full
     */

    bool Full() 
    {
        return (top >= size - 1);
    }

    /*
          Public int: Pop

          Description:
               Returns top value and removes it from stack

          Params:
               NULL

          Returns:
               [int] top value if any
     */

    int Pop()
    {
        if (!Empty())
        {
            if (top <= 10 && size <= 10)
            {
                return -1;
            }

            GetRatio();

            int data = A[top];
            top--;
            return data;
        }

        else
        {
            cout << "Error: Stack is Empty!" << endl;
            return -1;
        }
    }

    /*
          Public void: Print

          Description:
               Prints stack to standard out

          Params:
               NULL

          Returns:
               NULL
     */

    void Print() 
    {
        for (int i = 0; i <= top; i++) 
        {
            cout << A[i] << " ";
        }

        cout << endl;
    }

    /*
          Public bool: Push

          Description:
               Adds an item to top of stack

          Params:
               [int] : item to be added

          Returns:
               [bool] ; success = true
     */

    bool Push(int x)
    {
        if (Full()) 
        {
            ContainerGrow();
            A[++top] = x;
        }

        if (!Full())
        {
            GetRatio();
            A[++top] = x;
        }

        return false;
    }

    /*
          Public void: ContainerGrow

          Description:
               Resizes the container for the stack by doubling
               its capacity

          Params:
               NULL

          Returns:
               NULL
     */

    void ContainerGrow()
    {
        size = size * 2;
        cout << size << endl;
        int* B;                             // Creating a new dynamic array with double the memory
        B = new int[size];


        for (int i = 0; i < size; i++) {    // copy values to new array
            B[i] = A[i];
        }

        delete[] A;                         // delete old array

        A = B;                              // reset array pointer


        if (size > Max_Size)
        {
            Max_Size = size;
        }

        Resize++;                           // Keep track of resizing
    }


    /*
      Public void: ContainerShrink

      Description:
           Resizes the container for the stack by trimming
           its capacity by half.

      Params:
           NULL

      Returns:
           NULL
 */

    void ContainerShrink()
    {
        size = size / 2;                    // Trimming stack size in half

        if (size < 10)
        {
            size = 10;                      // "One hard rule: Never let stack get below size 10"
        }

        cout << size << endl;
        int* C;
        C = new int[size];

        for (int i = 0; i < size; i++)
        {
            C[i] = A[i];
        }

        delete[] A;                         // Free up the memory of A

        A = C;                              // Steer the pointer to the new array

        Resize++;                           // Keep track of resizing
    }


    // Retrieve the current Stack Size
    int GetStackSize()
    {
        return size;
    }


    // Retrieve the Maximum Stack Size variable
    int GetMaxSize()
    {
        return Max_Size;
    }


    // Retrieve the # of times Resizing occured
    int GetResize()
    {
        return Resize;
    }


    /*
          Public void: GetRatio

          Description:
               Computes the ratio of stack size
               to current # of items in the stack.
               Is called after each push or pop to
               see if resizing is needed.

          Params:
               NULL

          Returns:
               NULL
    
    */

    void GetRatio()
    {
        // Casting the int values as floats to do the division
        float T = top;
        float S = size;

        Ratio = ((T / S) * 100);


        /* 
            "Too Empty = 15% meaning in a stack of 100, if you get down to 15 items 
             you need to shrink your stack."
        */
        if (Ratio <= 15)
        {
            ContainerShrink();
        }
    }

    // Retrieve the top of the stack
    int GetTop()
    {
        return top;
    }

};



int main() 
{
    ArrayStack Stack;                       // Declairing an instance of ArrayStack
    ifstream in;
    ofstream out;

    // The three files the program was tested with

    in.open("nums_test.txt");
    //in.open("stacksample.txt");
    //in.open("nums.txt");


    // outfile destination
    out.open("StackP1_Results.txt");


    int temp;

    while (!in.eof())
    {
        in >> temp;

        if (temp % 2 == 0)                  // If Even
        {
            Stack.Push(temp);
        }
                                            // If Odd
        else
        {
            Stack.Pop();
        }

    }

    out << "######################################################################" << endl;
    out << setw(4) << "" << "Program 1 - Resizing the Stack" << endl;
    out << setw(4) << "" << "CMPS 3013" << endl;
    out << setw(4) << "" << "Byron Dowling" << endl << endl;
    out << setw(4) << "" << "Max Stack Size: " << Stack.GetMaxSize() << endl;
    out << setw(4) << "" << "End Stack Size: " << Stack.GetStackSize() << endl;
    out << setw(4) << "" << "Stack Resized: " << Stack.GetResize() << " times" << endl << endl;
    out << "######################################################################" << endl;

    in.close();                            // close the files
    out.close();

    return 0;
}