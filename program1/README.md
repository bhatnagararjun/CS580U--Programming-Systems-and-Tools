# CS580u Programming and System Tools
## Fall 2018
### PROGRAM 1 README FILE

## KNOWN BUGS AND INCOMPLETE PARTS:
- What parts of the program you were not able to complete

## REFERENCES:
- List any outside resources used

## MISCELLANEOUS COMMENTS:
- Anything you would like the grader to know

# Assignment Description
## Program 1 - Working with C
### Due Date: 5:00 p.m., September 14th, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Driver Code and Test Files

* program1.c
    * All of the function interfaces are provided for you. You just need to implement them. You must use the driver code as I have given you and only make alterations where stated. DO NOT change it to take user input, etc.

### Grading Rubric

**_TOTAL: 20 points_**
* **Part A: 10 points**
    * Test #1: Next Multiple [1 pt]
    * Test #2: Fahrenheit to Celsius [1 pt]
    * Test #3: Casting [3 pt]
    * Test #4: Fibonacci [5 pt]
* **Part B: 8 points**
    * Test #5: Prominent Color [8 pt]
* **Part C: 2 points**
    * Follows requested program structure and submission format

### Guidelines

This is an individual assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically *to* solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

__In this program, you will learn to__:

* Write basic C code
* Work with binary values

## Part A: Writing the Code

The included driver code has several functions that you must complete. Each function is described below. You __MUST__ not change the driver code (the main());

#### int findNextMultiple(int number1, int number2)
To round off an integer i to the next largest even multiple of another integer j, the following formula can be used:
* int next_multiple = i + j - i % j
    * For example, to round off 256 days to the next largest number of days evenly divisible by a week, values of i = 256 and j = 7 can be substituted into the preceding formula as follows:
    int next_multiple = 256 + 7 - 256 % 7

* Complete the function called `findNextMultiple` to find the next largest even multiple for the following values of i and j:
    *   |i|j|
        |--|--|
        |365|7|
        |12258|28|
        |996|4|

#### float convertFtoC(float fahrenheit)
Write a function, float convertFtoC(float fahrenheit), that converts 40° from degrees Fahrenheit (F) to degrees Celsius (C) using the following formula and returns the result:
    * C = (F - 32) / 1.8

#### int castToInt(long num), double castToDouble(long num), char castToChar(long num)
In the next part of the program we are going to see how choosing the wrong data types and careless casting can result in data loss. You should see inaccurate results. Complete the functions to typecast a long integer to the following datatypes
* int
* double
* char

### int fibonacci()
In the Fibonacci sequence, the first two Fibonacci numbers, called f0 and f1, are defined to be 0 and 1, respectively. Thereafter, each successive Fibonacci number fi is defined to be the sum of the two preceding Fibonacci numbers fi2 and fi1. So fi2 is calculated by adding together the values of fi0 and fi1.
     * Write a function that generates the first 20 fibonacci numbers _(including 0 and 1)_ using a loop.
     * You should return the final resulting value (the 20th value)

## Part B: Working with Colors

RGB (red, green, and blue) refers to a system for representing the colors to be used on a computer display. Red, green, and blue can be combined in various proportions to obtain any color in the visible spectrum. Intensity of each color is represented by the range of decimal numbers from 0 to 255 (256 levels for each color), equivalent to the range of binary numbers from 00000000 to 11111111, or hexadecimal 00 to FF.

For the second part of the assignment you will need to work with bit masking to determine the most prominent color in a given RGB value. You should return an integer corresponding to the most prominent color:

0. Unknown
1. Red
2. Green
3. Blue

You will need to separate the Red, Green, and Blue values, and determine which value is largest. Once you have determined the largest value, you must return the corresponding number for that color.

For example, the value 0xFF0000 would return 1 for Red, and 0x00FF00 would return 2 for Green.

If any two of the RGB colors are equal, the function should return 0.

## Part C: Submission
* Required code naming and organization:
    * program1.c

:no_entry: Every program will have a required submission guidelines. Please read submission requirements carefully. Any deviations from specifications on future programs will result in point deductions or incomplete grades.

## README

* KNOWN BUGS AND INCOMPLETE PARTS
* REFERENCES
* MISCELLANEOUS COMMENTS

Before your final submission, edit the content for each of these sections in this README for your program. You do not have to use markdown, but you can find out more about markdown [here](https://guides.github.com/features/mastering-markdown/) if you would like to.

### Git

Below is a reminder of the commands you need to use to submit your program.

:warning: *These commands all presume that your current working directory is within the directory tracked by `git`.*

```shell
git status
git commit -a -m "commit message"
git push
```

To find your most recent commit hash, use the following command:

```shell
git rev-parse HEAD
```    

To complete your submission, you must copy and paste this number into mycourses. Go to MyCourses, select cs580u, and **Assignment Hash Submission**.

:warning: You __MUST__ submit the commit hash on mycourses before the deadline to be considered on time **even if your program is completely working before the deadline**. :warning:
