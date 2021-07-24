#include <iostream>

#include "vector.hh"

using namespace std;

int main() {
  Vector<int, 10> vector{1, 2, 3, 4, 5};

  auto ptr = vector.Find(2);
  cout << ptr << endl;

  return 0;
}
