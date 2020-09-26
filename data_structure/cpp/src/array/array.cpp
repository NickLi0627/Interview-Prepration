#include "array.h"

#include <string.h>
#include <iostream>
#include <string>

template <typename T>
Array<T>::Array() : curr_size_(0), capacity_(0), data_(nullptr) {}

template <typename T>
Array<T>::Array(const Array<T>& copy_array) {
  *this = copy_array;
}

template <typename T>
Array<T>::~Array() {
  clear();
}

template <typename T>
T& Array<T>::operator[](const unsigned int idx) const {
  if (idx > curr_size_ - 1) {
    throw std::string("Invalid index, out of boundary");
  }
  return data_[idx];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& copy_array) {
  clear();

  curr_size_ = copy_array.curr_size_;
  capacity_ = copy_array.capacity_;

  data_ = new T[capacity_];
  if (curr_size_ > 0) {
    memcpy(data_, copy_array.data_, curr_size_ * sizeof(T));
  }
  return *this;
}

template <typename T>
bool Array<T>::operator==(const Array<T>& array) const {
  if (array.curr_size_ != curr_size_) {
    return false;
  }

  if (array.capacity_ != capacity_) {
    return false;
  }

  for (size_t i = 0; i < curr_size_; ++i) {
    if (array[i] != data_[i]) {
      return false;
    }
  }
  return true;
}

template <typename T>
void Array<T>::push(const T& value) {
  if (capacity_ == 0) {
    capacity_ = 1;
    data_ = new T[capacity_];
  } else if (curr_size_ >= capacity_) {
    capacity_ *= 2;

    T* temp = new T[capacity_];
    memcpy(temp, data_, curr_size_ * sizeof(T));
    delete[] data_;
    data_ = temp;
  }

  data_[curr_size_++] = value;
}

template <typename T>
void Array<T>::insert(const T& value, const unsigned int idx) {
  if (idx >= curr_size_) {
    throw std::string("Invalid index, out of boundary");
  }

  if (capacity_ == 0) {
    capacity_ = 1;
    data_ = new T[capacity_];
    data_[curr_size_++] = value;
  } else {
    capacity_ = idx >= curr_size_ ? 2 * capacity_ : capacity_;

    T* temp = new T[capacity_];
    memcpy(temp, data_, idx * sizeof(T));
    temp[idx] = value;

    memcpy(&temp[idx + 1], &data_[idx], (curr_size_ - idx) * sizeof(T));

    delete[] data_;
    data_ = temp;
    ++curr_size_;
  }
}

template <typename T>
void Array<T>::erase(const unsigned int idx) {
  if (idx >= curr_size_) {
    throw std::string("Invalid index, out of boundary");
  }

  if (capacity_ > 0) {
    T* temp = new T[capacity_];
    memcpy(temp, data_, idx * sizeof(T));
    memcpy(&temp[idx], &data_[idx + 1], (curr_size_ - idx - 1) * sizeof(T));
    delete[] data_;
    data_ = temp;
    --curr_size_;
  }
}

template <typename T>
void Array<T>::clear() {
  if (capacity_ > 0) {
    delete[] data_;
    curr_size_ = 0;
    capacity_ = 0;
    data_ = nullptr;
  }
}

template <typename T>
size_t Array<T>::size() {
  return curr_size_;
}

template class Array<int>;
template class Array<std::string>;
