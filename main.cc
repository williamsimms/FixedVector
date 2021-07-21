#include <iostream>
#include <cstdlib>
#include <vector>

#include "vector.hh"

using namespace std;

int main() {
vector<int> numbers;
numbers.reserve(20);

for (int i=0; i < 20 ; i++) {
numbers[i] = i * 45 %13; 
}


for (int i=0; i < 20 ; i++) {
cout << numbers[i] << endl; 
}

  return 0;
}
