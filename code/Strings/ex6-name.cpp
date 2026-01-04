#include <iostream>
#include <string>
using namespace std;

int main() {

  string name;      // User name, input
  string middle;    // middle name, input
  int spacePos = 0; // Position of space in name.

  cout << "Please enter your name, followed by the \"Enter\" key: ";
  getline(cin, name);
  cout << "Your name is: \"" << name << "\"\n";
  cout << "Your name contains " << name.length() << " characters." << endl;

  spacePos = name.find(" ");
  cout << "Formal form: " << name.at(0) << ". ";
  cout << name.substr(spacePos + 1, name.length()) << endl;

  cout << "Please enter your middle name: ";
  cin >> middle;

  name.insert(spacePos + 1, middle + "");
  // name.insert(spacePos+middle.length()+1, " ");
  cout << "Full name: " << name << endl;

  return 0;
}
