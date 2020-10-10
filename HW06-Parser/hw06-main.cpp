#include <iostream>

#include "Parser.h"

using namespace std;

int main(){

  string input;
  Parser p;

  cout << "Type exit to exit." << endl;

  cout << ">";
  getline(cin, input);
  while(input != "exit"){
    cout << p.parse(input) << endl;
    cout << ">";
    getline(cin, input);
  }
  cout << "Exiting!" << endl;
}