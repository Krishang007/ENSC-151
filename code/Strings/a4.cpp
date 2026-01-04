#include <iostream>
#include <string>
using namespace std;

void reverseString(string s);
int main()
{
    string s;
    // user input
    cout << "Enter four words seperated by *:";
      getline(cin, s); 
    reverseString(s);
    
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
void reverseString(string s)
{
    // find position of * using s.find function
    //  where s.find('delimmiter')
    //* is the delimiter
    int pos1 = s.find('*');
    int pos2 = s.find('*', pos1 + 1);
    int pos3 = s.find('*', pos2 + 1);

    // extract words using substr funciton
    string word1 = s.substr(0, pos1);
    string word2 = s.substr(pos1 + 1, pos2 - pos1 - 1);
    string word3 = s.substr(pos2 + 1, pos3 - pos2 - 1);
    string word4 = s.substr(pos3 + 1);
    // reversed string with spaces
    //concetrations 
    string reversed = word4 + " " + word3 + " " + word2 + " " + word1;

    // output
   // cout << s << endl;        // original string
    cout << reversed << endl; // reversed string
}

