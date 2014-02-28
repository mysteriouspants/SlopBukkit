/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140227, Chapter 10 Programming Challenge 16
 */

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

vector<string> split_words(string&);
string pig_latinize(string&);

int main() {
  string input;
  vector<string> words;
  vector<string> verba;
  
  cout << "Please enter a sentence: ";
  getline(cin, input);
  
  words = split_words(input);
  
  for (auto iter = words.begin(); iter != words.end(); iter++) {
    verba.push_back(pig_latinize(*iter));
  }
  
  cout << "Pig latin: ";
  
  for (auto iter = verba.begin(); iter != verba.end(); iter++) {
    cout << *iter << " ";
  }
  
  cout << endl;
  
  return 0;
}

vector<string> split_words(string& sz0) {
  vector<size_t> space_locations;
  vector<string> words;
  size_t u = 0;
  
  space_locations.push_back(0);
  for(size_t pos = 0; pos < sz0.length(); ++pos) {
    u = sz0.find(' ',pos);
    if (u == string::npos) break;
    space_locations.push_back(u+1);
    pos = u;
  }
  space_locations.push_back(sz0.length());
  
  for (size_t i = 1; i < space_locations.size(); ++i) {
    words.push_back(
      sz0.substr(space_locations[i-1],space_locations[i]-space_locations[i-1]-1)
    );
  }
  
  return words;
}

string pig_latinize(string& sz0) {
  string verbo = sz0.substr(1, sz0.length()-1);
  verbo += sz0[0];
  verbo += "ay";
  return verbo;
}