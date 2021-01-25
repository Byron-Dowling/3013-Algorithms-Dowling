## Program 1 - Resizing the Stack
### Byron Dowling

### Original Description:

- The stack implementation has a `Resize` method that ONLY will make the stack larger as we add items. 
- This means that the stack will never shrink if we remove many items. 
- We should probably remedy this issue.
- Too Full = 100% meaning no extra slots available in your array. 
- Too Empty = 15% meaning in a stack of 100, if you get down to 15 items you need to shrink your stack.
- Enlarging = Double the size of the stack.
- Shrinking - Cut the size of the stack in half. 


#### Testing Your Code

- You will read numbers from the file [nums_test.dat](./nums_test.dat).
- If a number is even, push it onto the stack. 
- If a number is odd, perform a pop operation removing the last even value from the stack. 
- Don't let your stack get smaller than **10** (our starting stack size).
- You need to keep track of the following:
  - the **max size** the stack ever reached
  - **how many times** the stack was resized (grown or reduced)
  - **final size** of stack when program completed

### Files
|   #   | File                | Description                                        |
| :---: | --------------------| -------------------------------------------------- |
|   1   | 3013 Stack Main.cpp | Main driver of my project                          |
|   2   | nums_test.txt       | 1 of 3 input files that were tested                |
|   3   | nums.txt            | 1 of 3 input files that were tested                |
|   4   | stacksample.txt     | 1 of 3 input files that were tested                |
|   5   | StackP1_Results.txt | Output file for final decrypted text               |
