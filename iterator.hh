#ifndef ITERATOR_H
#define ITERATOR_H

template <typename Vector>
class Iterator {
 public:
  using ValueType = typename Vector::ValueType;
  using PointerType = ValueType*;
  using ConstPointerType = const ValueType*;
  using ReferenceType = ValueType&;
  using ConstReferenceType = const ValueType&;

 private:
  PointerType data;

 public:
  explicit Iterator(PointerType ptr) : data{ptr} {}

  Iterator& operator++() noexcept {
    data++;
    return *this;
  }

  Iterator operator++(int) noexcept {
    Iterator iterator(*this);
    ++data;
    return iterator;
  }

  Iterator& operator--() noexcept {
    --data;
    return *this;
  }

  Iterator operator--(int) noexcept {
    Iterator iterator(*this);
    --data;
    return iterator;
  }

  ReferenceType operator[](int index) { return *(data + index); }

  PointerType operator->() const { return data; }

  ReferenceType operator*() const { return *data; }

  bool operator==(const Iterator& other) const { return data == other.data; }

  bool operator!=(const Iterator& other) const { return !(data == other.data); }

  operator Iterator<const Iterator>() const {
    return Iterator<const Iterator>(data);
  }
};

#endif