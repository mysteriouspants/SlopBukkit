#include <iostream>
using namespace std;

int fib_r(int);

int main(int argc, char *argv[]) {
  for (int i = 1; i <= 45; i++) {
    cout << "fib_r(" << i << "): " << fib_r(i) << endl;
  }
}

int fib_r(int n) {
  if (n <= 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return fib_r(n - 1) + fib_r(n - 2);
}