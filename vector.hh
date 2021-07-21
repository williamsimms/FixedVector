#ifndef VECTOR_H
#define VECTOR_H

#include <array>
#include <cstddef>
#include <iostream>
#include <memory>
#include <utility>

template <typename T, int N>
class Vector {
  Vector();
  Vector(const Vector<T, N>&);
  Vector(Vector<T, N>&&);
  ~Vector();

  Vector<T, N>& operator=(const Vector<T, N>&);
  Vector<T, N>& operator=(Vector<T, N>&&);

  int Size();
  T& At();

  void PushBack(const T&);
};

#endif