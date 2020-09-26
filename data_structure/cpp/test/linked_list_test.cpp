#include "linked_list.h"

#include "gtest/gtest.h"

TEST(linked_list, TEST_ALL) {
  LinkedList<int> data;

  data.add_first(1);
  data.add_first(5);
  ASSERT_EQ(data.get(0), 5);
  ASSERT_EQ(data.get(1), 1);
  ASSERT_EQ(data.size(), 2);

  data.add_last(4);
  data.add_last(3);
  ASSERT_EQ(data.get(2), 4);
  ASSERT_EQ(data.get(3), 3);
  ASSERT_EQ(data.size(), 4);

  data.insert(10, 1);
  data.insert(20, 2);
  ASSERT_EQ(data.get(0), 5);
  ASSERT_EQ(data.get(1), 10);
  ASSERT_EQ(data.get(2), 20);
  ASSERT_EQ(data.get(3), 1);
  ASSERT_EQ(data.get(4), 4);
  ASSERT_EQ(data.get(5), 3);
  ASSERT_EQ(data.size(), 6);

  data.remove_first();
  ASSERT_EQ(data.get(0), 10);
  ASSERT_EQ(data.get(1), 20);
  ASSERT_EQ(data.get(2), 1);
  ASSERT_EQ(data.get(3), 4);
  ASSERT_EQ(data.get(4), 3);
  ASSERT_EQ(data.size(), 5);

  data.remove_last();
  ASSERT_EQ(data.get(0), 10);
  ASSERT_EQ(data.get(1), 20);
  ASSERT_EQ(data.get(2), 1);
  ASSERT_EQ(data.get(3), 4);
  ASSERT_EQ(data.size(), 4);

  data.remove(0);
  data.remove(2);
  ASSERT_EQ(data.get(0), 20);
  ASSERT_EQ(data.get(1), 1);
  ASSERT_EQ(data.size(), 2);

  data.clear();
  ASSERT_EQ(data.size(), 0);
}
