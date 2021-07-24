#ifndef VECTOR_H
#define VECTOR_H

#include <array>
#include <cassert>
#include <initializer_list>
#include <iostream>
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
  constexpr Vector() noexcept;
  constexpr Vector(const Vector<T, N>&) noexcept;
  constexpr Vector(Vector<T, N>&&) noexcept;
  constexpr Vector(const std::initializer_list<T>&) noexcept;
  constexpr Vector(const std::array<T, N>&) noexcept;
  constexpr Vector(const T&) noexcept;
  ~Vector() noexcept;

  Vector<T, N>& operator=(const Vector<T, N>&) noexcept;
  Vector<T, N>& operator=(Vector<T, N>&&) noexcept;
  bool operator==(const Vector<T, N>&) const noexcept;
  bool operator!=(const Vector<T, N>&) const noexcept;

  T& operator[](int index) noexcept;
  const T& operator[](int index) const noexcept;

  int Size() const noexcept;
  constexpr int Capacity() const noexcept;
  constexpr int FreeCapacity() const noexcept;

  T& At(int) noexcept;
  const T& At(int) const noexcept;

  void PushBack(const T&) noexcept;
  void PushBack(T&&) noexcept;

  template <typename... Args>
  void EmplaceBack(Args&&... args) noexcept;

  void PopBack() noexcept;

  bool Empty() noexcept;

  const T& Front() const;
  const T& Back() const;
  T& Front();
  T& Back();

  T* Data() noexcept;
  const T* Data() const noexcept;

  T* Find(const T&) const;
  int IndexOf(const T&) noexcept;
  bool Contains(const T&) noexcept;

  void Print() const;

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

  template <typename U, int V>
  friend std::ostream& operator<<(std::ostream&, const Vector<U, V>&);
};

template <typename T, int N>
constexpr Vector<T, N>::Vector() noexcept : size(0) {}

template <typename T, int N>
constexpr Vector<T, N>::Vector(const Vector<T, N>& vector) noexcept {
  for (int i = 0; i < N; i++) {
    data[i] = vector.data[i];
  }

  this->size = vector.size;
}

template <typename T, int N>
constexpr Vector<T, N>::Vector(Vector<T, N>&& vector) noexcept {
  this->data = vector.data;
  this->size = vector.size;
  this->capacity = vector.capacity;
  vector.data = nullptr;
  vector.size = 0;
  vector.capacity = 0;
}

template <typename T, int N>
constexpr Vector<T, N>::Vector(const std::initializer_list<T>& list) noexcept
    : size(0) {
  for (const T& value : list) {
    PushBack(std::move(value));
  }
}

template <typename T, int N>
constexpr Vector<T, N>::Vector(const std::array<T, N>& arr) noexcept {
  for (int i = 0; i < N; i++) {
    data[i] = std::move(arr.at(i));
  }
}

template <typename T, int N>
constexpr Vector<T, N>::Vector(const T& value) noexcept {
  for (int i = 0; i < N; i++) {
    data[i] = value;
  }
}

template <typename T, int N>
Vector<T, N>::~Vector() noexcept = default;

template <typename T, int N>
Vector<T, N>& Vector<T, N>::operator=(const Vector<T, N>& vector) noexcept {
  if (this == &vector) {
    return *this;
  }

  for (int i = 0; i < N; i++) {
    data[i] = vector.data[i];
  }

  this->size = vector.size;
  return *this;
}

template <typename T, int N>
Vector<T, N>& Vector<T, N>::operator=(Vector<T, N>&& vector) noexcept {
  if (this == &vector) {
    return *this;
  }

  this->data = vector.data;
  vector.data = nullptr;
  vector.size = 0;
  vector.capacity = 0;
  return *this;
}

template <typename T, int N>
T& Vector<T, N>::operator[](int index) noexcept {
  assert(index >= 0);
  assert(index < capacity);
  return this->data[index];
}

template <typename T, int N>
const T& Vector<T, N>::operator[](int index) const noexcept {
  assert(index >= 0);
  assert(index < capacity);
  return this->data[index];
}

template <typename T, int N>
int Vector<T, N>::Size() const noexcept {
  return size;
}

template <typename T, int N>
constexpr int Vector<T, N>::Capacity() const noexcept {
  return capacity;
}

template <typename T, int N>
constexpr int Vector<T, N>::FreeCapacity() const noexcept {
  return capacity - size;
}

template <typename T, int N>
T& Vector<T, N>::At(int index) noexcept {
  assert(index >= 0);
  assert(index < capacity);
  return this->data[index];
}

template <typename T, int N>
const T& Vector<T, N>::At(int index) const noexcept {
  assert(index >= 0);
  assert(index < capacity);
  return this->data[index];
}

template <typename T, int N>
void Vector<T, N>::PushBack(const T& value) noexcept {
  if (size == capacity) {
    return;
  }

  data[size] = value;
  this->size++;
}

template <typename T, int N>
void Vector<T, N>::PushBack(T&& value) noexcept {
  if (size == capacity) {
    return;
  }

  data[size] = std::move(value);
  this->size++;
}

template <typename T, int N>
template <typename... Args>
void Vector<T, N>::EmplaceBack(Args&&... args) noexcept {
  if (size == capacity) {
    return;
  }

  data[size] = T(std::forward<Args>(args)...);
  this->size++;
}

template <typename T, int N>
void Vector<T, N>::PopBack() noexcept {
  this->size--;
}

template <typename T, int N>
bool Vector<T, N>::Empty() noexcept {
  if (size > 0) {
    return false;
  }

  return true;
}

template <typename T, int N>
const T& Vector<T, N>::Front() const {
  return data[0];
}

template <typename T, int N>
const T& Vector<T, N>::Back() const {
  return data[size - 1];
}

template <typename T, int N>
T& Vector<T, N>::Front() {
  return data[0];
}

template <typename T, int N>
T& Vector<T, N>::Back() {
  return data[size - 1];
}

template <typename T, int N>
T* Vector<T, N>::Data() noexcept {
  return this->data;
}

template <typename T, int N>
const T* Vector<T, N>::Data() const noexcept {
  return this->data;
}

template <typename T, int N>
T* Vector<T, N>::Find(const T& value) const {
  for (int i = 0; i < capacity; i++) {
    if (data[i] == value) {
      return data[i];
    }
  }

  return nullptr;
}

template <typename T, int N>
int Vector<T, N>::IndexOf(const T& value) noexcept {
  for (int i = 0; i < capacity; i++) {
    if (data[i] == value) {
      return i;
    }
  }

  return -1;
}

template <typename T, int N>
bool Vector<T, N>::Contains(const T& value) noexcept {
  for (int i = 0; i < capacity; i++) {
    if (data[i] == value) {
      return true;
    }
  }

  return false;
}

template <typename T, int N>
void Vector<T, N>::Print() const {
  if (size == 0) {
    return;
  }

  std::cout << "[";
  for (int i = 0; i < size; i++) {
    std::cout << data[i];

    if (i < (size - 1)) {
      std::cout << ", ";
    }
  }

  std::cout << "]" << std::endl;
}

template <typename T, int N>
bool Vector<T, N>::operator==(const Vector<T, N>& vector) const noexcept {
  for (int i = 0; i < size; i++) {
    if (data[i] != vector[i]) {
      return false;
    }
  }

  return true;
}

template <typename T, int N>
bool Vector<T, N>::operator!=(const Vector<T, N>& vector) const noexcept {
  return !(*this == vector);
}

template <typename T, int N>
std::ostream& operator<<(std::ostream& os, const Vector<T, N>& vector) {
  vector.Print();
  return os;
}

#endif