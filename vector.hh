#ifndef VECTOR_H
#define VECTOR_H

#include <array>
#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>

#include "iterator.hh"
#include "reverseiterator.hh"

template <typename T, int N>
class Vector {
 public:
  using ValueType = T;
  using PointerType = T*;
  using ConstPointer = const T*;
  using ReferenceType = T&;
  using ConstReferenceType = const T&;

  // using Iterator = VectorIterator<Vector<T, N>>;
  // using ConstIterator = VectorIterator<const Vector<T, N>>;
  // using ReverseIterator = ReverseIterator<Vector<T, N>>;
  // using ConstReverseIterator = ReverseVectorIterator<const Vector<T, N>>;

 private:
  T data[N];
  int size;
  int capacity = N;

 public:
  Vector();
  Vector(const Vector<T, N>&);
  Vector(Vector<T, N>&&);
  Vector(const std::initializer_list<T>&);
  Vector(const std::array<T, N>&);
  Vector(const T&);
  ~Vector();

  Vector<T, N>& operator=(const Vector<T, N>&);
  Vector<T, N>& operator=(Vector<T, N>&&);

  int Size();
  int Capacity();
  int FreeCapacity();
  T& At();

  void PushBack(const T&);
  void PushBack(T&&);

  void Insert(int index, const T&);
  void Insert(int index, T&&);

  template <typename... Args>
  void EmplaceBack(Args&&... args);

  void PopBack();

  bool Empty();

  void Print();

  friend std::ostream& operator<<(std::ostream&, const Vector<T, N>&);
};

template <typename T, int N>
Vector<T, N>::Vector() {
  //
}

template <typename T, int N>
Vector<T, N>::Vector(const Vector<T, N>&) {
  //
}

template <typename T, int N>
Vector<T, N>::Vector(Vector<T, N>&&) {
  //
}

template <typename T, int N>
Vector<T, N>::Vector(const std::initializer_list<T>&) {
  //
}

template <typename T, int N>
Vector<T, N>::Vector(const std::array<T, N>&) {
  //
}

template <typename T, int N>
Vector<T, N>::Vector(const T&) {
  //
}

template <typename T, int N>
Vector<T, N>::~Vector() {
  //
}

#endif