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

  using ConstIterator = Iterator<const Vector<T, N>>;
  using Iterator = Iterator<Vector<T, N>>;
  using ConstReverseIterator = ReverseIterator<const Vector<T, N>>;
  using ReverseIterator = ReverseIterator<Vector<T, N>>;

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

  T& operator[](int index);
  const T& operator[](int index) const;

  int Size() const;
  int Capacity() const;
  int FreeCapacity() const;
  T& At();
  const T& At() const;

  void PushBack(const T&);
  void PushBack(T&&);

  void Insert(int index, const T&);
  void Insert(int index, T&&);

  template <typename... Args>
  void EmplaceBack(Args&&... args);

  void Assign(const std::initializer_list<T>&);
  void Assign(const std::array<T, N>&);
  void Assign(int count, const T& value);

  void PopBack();
  void Erase(int index);

  bool Empty();

  const T& Front() const;
  const T& Back() const;
  const T& Middle() const;
  T& Front();
  T& Back();
  T& Middle();

  void Swap(T*, T*);
  T* Data();
  const T* Data() const;

  T* Find(const T&) const;
  int IndexOf(const T&);
  bool Contains(const T&);

  void Print();

  Iterator begin() {
    Iterator it(data);
    return it;
  }

  Iterator end() {
    Iterator it(data + size);
    return it;
  }

  ConstIterator cbegin() {
    ConstIterator it(data);
    return it;
  }

  ConstIterator cend() {
    ConstIterator it(data + size);
    return it;
  }

  ReverseIterator rbegin() {
    ReverseIterator it(data + size);
    return it;
  }

  ReverseIterator rend() {
    ReverseIterator it(data);
    return it;
  }

  ConstReverseIterator crbegin() {
    ConstReverseIterator it(data + size);
    return it;
  }

  ConstReverseIterator crend() {
    ConstReverseIterator it(data);
    return it;
  }

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