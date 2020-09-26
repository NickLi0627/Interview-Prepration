#include "linked_list.h"

#include <string.h>
#include <iostream>
#include <string>

template <typename T>
LinkedList<T>::LinkedList() : size_(0), head_(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
  clear();
}

template <typename T>
void LinkedList<T>::add_first(const T& value) {
  auto node = new Node(value);
  node->next_ = head_;
  head_ = node;
  ++size_;
}

template <typename T>
void LinkedList<T>::add_last(const T& value) {
  if (head_ == nullptr) {
    head_ = new Node(value);
    ++size_;
    return;
  }

  auto current = head_;
  while (current->next_) {
    current = current->next_;
  }

  current->next_ = new Node(value);
  ++size_;
}

template <typename T>
void LinkedList<T>::insert(const T& value, const unsigned int idx) {
  if (idx >= size_) {
    throw std::string("Invalid index, out of boundary");
  }

  if (idx == 0) {
    add_first(value);
    return;
  }

  auto current = head_;
  for (unsigned int i = 0; i < idx - 1; ++i) {
    current = current->next_;
  }
  auto temp = current->next_;

  current->next_ = new Node(value);
  current->next_->next_ = temp;
  ++size_;
}

template <typename T>
void LinkedList<T>::remove_first() {
  if (head_ == nullptr) {
    return;
  }
  auto temp = head_;
  head_ = head_->next_;
  delete temp;
  --size_;
}

template <typename T>
void LinkedList<T>::remove_last() {
  if (head_ == nullptr) {
    return;
  }
  auto current = head_;
  auto next = current->next_;
  while (next->next_) {
    current = current->next_;
    next = next->next_;
  }
  current->next_ = nullptr;
  delete next;
  --size_;
}

template <typename T>
void LinkedList<T>::remove(const unsigned int idx) {
  if (idx >= size_) {
    throw std::string("Invalid index, out of boundary");
  }

  if (idx == 0) {
    remove_first();
    return;
  }

  auto current = head_;
  for (unsigned int i = 0; i < idx - 1; ++i) {
    current = current->next_;
  }

  auto temp = current->next_;
  current->next_ = current->next_->next_;
  delete temp;
  --size_;
}

template <typename T>
T LinkedList<T>::get(const unsigned idx) {
  if (idx >= size_) {
    throw std::string("Invalid index, out of boundary");
  }

  auto current = head_;
  for (unsigned int i = 0; i < idx; ++i) {
    current = current->next_;
  }
  return current->data_;
}

template <typename T>
void LinkedList<T>::clear() {
  while (head_->next_) {
    auto temp = head_->next_;
    delete head_;
    head_ = temp;
  }
  size_ = 0;
}

template <typename T>
size_t LinkedList<T>::size() {
  return size_;
}

template class LinkedList<int>;
