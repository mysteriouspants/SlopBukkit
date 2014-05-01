#include <iostream>
using namespace std;

/* note that the original version in the textbook looped infinitely */
/* i am assuming that this version is what the author intended */
void iter_sign(int n) {
  while (n > 0) {
    cout << "No parking\n";
    n--;
  }
}

void recur_sign(int n) {
  if (n > 0) {
    cout << "No parking\n";
    recur_sign(n-1);
  }
}

int main(int argc, char *argv[]) {
  cout << "recursive version:" << endl;
  recur_sign(10);
  return 0;
}