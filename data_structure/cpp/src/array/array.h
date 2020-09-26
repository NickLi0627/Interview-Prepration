#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>

template <typename T>
class Array {
 public:
  Array();
  Array(const Array<T>& copy_array);
  ~Array();

  // Common functions for array
  void push(const T& value);
  void insert(const T& value, const unsigned int idx);
  void erase(const unsigned int idx);
  void clear();
  size_t size();

  // Operator overloading
  Array<T>& operator=(const Array<T>& copy_array);
  T& operator[](const unsigned int idx) const;
  bool operator==(const Array<T>& array) const;

 private:
  std::size_t curr_size_;
  std::size_t capacity_;
  T* data_;
};

#endif  // ARRAY_H_