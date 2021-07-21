#ifndef VECTOR_H
#define VECTOR_H

#include <array>
#include <cassert>
#include <cstddef>
#include <functional>
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
  Vector() noexcept;
  Vector(const Vector<T, N>&) noexcept;
  Vector(Vector<T, N>&&) noexcept;
  Vector(const std::initializer_list<T>&) noexcept;
  Vector(const std::array<T, N>&) noexcept;
  Vector(const T&) noexcept;
  ~Vector() noexcept;

  Vector<T, N>& operator=(const Vector<T, N>&) noexcept;
  Vector<T, N>& operator=(Vector<T, N>&&) noexcept;

  T& operator[](int index) noexcept;
  const T& operator[](int index) const noexcept;

  int Size() const noexcept;
  int Capacity() const noexcept;
  int FreeCapacity() const noexcept;
  T& At() noexcept;
  const T& At() const noexcept;

  void PushBack(const T&) noexcept;
  void PushBack(T&&) noexcept;

  void Insert(int index, const T&) noexcept;
  void Insert(int index, T&&) noexcept;

  template <typename... Args>
  void EmplaceBack(Args&&... args) noexcept;

  void Assign(const std::initializer_list<T>&) noexcept;
  void Assign(const std::array<T, N>&) noexcept;
  void Assign(int count, const T& value) noexcept;

  void PopBack() noexcept;
  void Erase(int index) noexcept;

  bool Empty() noexcept;

  const T& Front() const;
  const T& Back() const;
  const T& Middle() const;
  T& Front();
  T& Back();
  T& Middle();

  void Swap(T*, T*) noexcept;
  T* Data() noexcept;
  const T* Data() const noexcept;

  T* Find(const T&) const;
  int IndexOf(const T&) noexcept;
  bool Contains(const T&) noexcept;

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
Vector<T, N>::Vector() noexcept {
  //
}

template <typename T, int N>
Vector<T, N>::Vector(const Vector<T, N>&) noexcept {
  //
}

template <typename T, int N>
Vector<T, N>::Vector(Vector<T, N>&&) noexcept {
  //
}

template <typename T, int N>
Vector<T, N>::Vector(const std::initializer_list<T>&) noexcept {
  //
}

template <typename T, int N>
Vector<T, N>::Vector(const std::array<T, N>&) noexcept {
  //
}

template <typename T, int N>
Vector<T, N>::Vector(const T&) noexcept {
  //
}

template <typename T, int N>
Vector<T, N>::~Vector() noexcept {
  //
}

template <typename T, int N>
Vector<T, N>& Vector<T, N>::operator=(const Vector<T, N>&) noexcept {
  //
}

template <typename T, int N>
Vector<T, N>& Vector<T, N>::operator=(Vector<T, N>&&) noexcept {
  //
}

template <typename T, int N>
T& Vector<T, N>::operator[](int index) noexcept {
  //
}

template <typename T, int N>
const T& Vector<T, N>::operator[](int index) const noexcept {
  //
}

template <typename T, int N>
int Vector<T, N>::Size() const noexcept {
  //
}

template <typename T, int N>
int Vector<T, N>::Capacity() const noexcept {
  //
}

template <typename T, int N>
int Vector<T, N>::FreeCapacity() const noexcept {
  //
}

template <typename T, int N>
T& Vector<T, N>::At() noexcept {
  //
}

template <typename T, int N>
const T& Vector<T, N>::At() const noexcept {
  //
}

#endif