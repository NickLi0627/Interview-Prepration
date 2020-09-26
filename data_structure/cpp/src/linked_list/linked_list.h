#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <iostream>

template <typename T>
class Node {
 public:
  Node(const T& value) : data_(value) {}

  T data_;
  Node<T>* next_ = nullptr;
};

template <typename T>
class LinkedList {
 public:
  LinkedList();
  ~LinkedList();

  // Common functions for linked list
  void add_first(const T& value);
  void add_last(const T& value);
  void insert(const T& value, const unsigned int idx);

  void remove_first();
  void remove_last();
  void remove(const unsigned int idx);

  T get(const unsigned idx);
  void clear();
  size_t size();

 private:
  Node<T>* head_;
  size_t size_;
};

#endif  // LINKED_LIST_