/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * assign4.cpp --
 * Input: string with 4 words separated with *
 * Output: reversed string
 * author: Krishang Sarkar
 *******************************************************************/

// libraries used in the program
#include <iostream>
#include <string>
using namespace std;

// function declaration
void reverseWords(const string &inputStr, string &reversedStr);

/******************************************************************
 * main --
 * Parameters: none
 * Modifies: cin, cout
 * Returns: 0
 *******************************************************************/
int main() {
    // variable declaration
    string s, result;

    // input
    cout << "Enter a string with 4 words separated with * : ";
    cin >> s;

    // function call
    reverseWords(s, result);

    // output
    cout << s << endl;
    cout << result << endl;

    return 0;
}

/******************************************************************
 * reverseWords --
 * Parameters: const string& inputStr, string& reversedStr
 * Returns: nothing (void)
 * Purpose:
 *    extracts 4 words separated by '*' using a loop,
 *    stores them in an array, and builds the reversed output string
 *******************************************************************/
void reverseWords(const string &inputStr, string &reversedStr) {
    // array to store words
    string words[4];

    int start = 0;
    int end;
    int count = 0;

    // extract words separated by '*'
    while ((end = inputStr.find('*', start)) != string::npos && count < 3) {
        words[count++] = inputStr.substr(start, end - start);
        start = end + 1;
    }

    // extract last word
    words[count] = inputStr.substr(start);

    // build reversed string
    reversedStr = words[3] + " " + words[2] + " " + words[1] + " " + words[0];
}