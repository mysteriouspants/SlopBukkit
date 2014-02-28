/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140227, Chapter 10 Programming Challenge 18
 */

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

#define MIN(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
    
int main(int argc, char *argv[]) {
  vector<string> haystack = {
    "Becky Warren, 555-1223",
    "Joe Looney, 555-0097",
    "Geri Palmer, 555-8787",
    "Lynn Presnell, 555-1212",
    "Holly Gaddis, 555-8878",
    "Sam Wiggins, 555-0998",
    "Bob Kain, 555-8712",
    "Tim Haynes, 555-7676",
    "Warren Gaddis, 555-9037",
    "Jean James, 555-4939",
    "Ron Palmer, 555-2783"
  };
  vector<size_t> idx_matches;
  string needle;
  
  
  cout << "Please enter a needle: ";
  getline(cin, needle);
  
  for (size_t i = 0; i < haystack.size(); ++i) {
    if (NULL == strnstr(haystack[i].c_str(), needle.c_str(), MIN(haystack[i].length(), needle.length()))) {
      continue;
    }
    idx_matches.push_back(i);
  }
  
  cout << "Matches:" << endl;
  for (size_t i = 0; i < idx_matches.size(); ++i) {
    cout << "  " << haystack[idx_matches[i]] << endl;
  }
  
  return 0;
}