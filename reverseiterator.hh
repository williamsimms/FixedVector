#ifndef REVERSE_ITERATOR_H
#define REVERSE_ITERATOR_H

template <typename Vector>
class ReverseIterator {
 public:
  using ValueType = typename Vector::ValueType;
  using PointerType = ValueType*;
  using ReferenceType = ValueType&;

 private:
  PointerType data;

 public:
  explicit ReverseIterator(PointerType ptr) : data{ptr} {}

  ReverseIterator& operator++() noexcept {
    data--;
    return *this;
  }

  ReverseIterator operator++(int) noexcept {
    ReverseIterator iterator(*this);
    --data;
    return iterator;
  }

  ReverseIterator& operator--() noexcept {
    ++data;
    return *this;
  }

  ReverseIterator operator--(int) noexcept {
    ReverseIterator iterator(*this);
    ++data;
    return iterator;
  }

  ReferenceType operator[](int index) { return *(data - index); }

  PointerType operator->() const { return data; }

  ReferenceType operator*() const { return *data; }

  bool operator==(const ReverseIterator& other) const {
    return data == other.data;
  }

  bool operator!=(const ReverseIterator& other) const {
    return !(data == other.data);
  }

  operator ReverseIterator<const ReverseIterator>() const {
    return ReverseIterator<const ReverseIterator>(data);
  }
};

#endif