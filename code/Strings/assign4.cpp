/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * assign4.cpp --
 * Input:string with 4 words seperated with *
 * Output: reversed string
 * authour:krishang Sarkar
 *******************************************************************/
// libraries and preprocesser directives used in the program
#include <iostream>
#include <string>
using namespace std;
// decalering fucntion used in the program
// non value returning functioa to reverse the string
void reverseWords(string s);

/******************************************************************
 * main --
 * Parameters: none
 * Modifies: cin, cout -- for user interaction
 * Returns: 0
 *******************************************************************/
int main() {
  // variable declarations for the program
  string s;

  // input statement
  cout << "Enter a string with 4 words separated with * : ";
  cin >> s;

  // calls the reverse function
  reverseWords(s);

  return 0;
}

// implementation of the reverseWords function
/******************************************************************
 * reverseWords --
 * Parameters: string s
 * Returns: nothing as it is a void function
 * Purpose: extracts words separated by '*' and prints them
 *          in reverse order, separated by spaces.
 *******************************************************************/
void reverseWords(string s) {
  // find positions of '*' characters parsed in the string
  int pos1 = s.find('*');
  int pos2 = s.find('*', pos1 + 1);
  int pos3 = s.find('*', pos2 + 1);

  // extract words using substr() function
  string word1 = s.substr(0, pos1);
  string word2 = s.substr(pos1 + 1, pos2 - pos1 - 1);
  string word3 = s.substr(pos2 + 1, pos3 - pos2 - 1);
  string word4 = s.substr(pos3 + 1);

  // reversed string with spaces
  string reversed = word4 + " " + word3 + " " + word2 + " " + word1;

  // output
  cout << s << endl;        // original string
  cout << reversed << endl; // reversed string
}