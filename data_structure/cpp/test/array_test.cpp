#include "array.h"

#include <unordered_map>
#include "gtest/gtest.h"

TEST(array, TEST_ALL) {
  Array<int> data;
  ASSERT_EQ(data.size(), 0);

  data.push(1);
  data.push(2);
  data.push(4);
  ASSERT_EQ(data[0], 1);
  ASSERT_EQ(data[1], 2);
  ASSERT_EQ(data[2], 4);
  ASSERT_EQ(data.size(), 3);

  data.erase(1);
  ASSERT_EQ(data[0], 1);
  ASSERT_EQ(data[1], 4);
  ASSERT_EQ(data.size(), 2);

  data.insert(5, 1);
  ASSERT_EQ(data[0], 1);
  ASSERT_EQ(data[1], 5);
  ASSERT_EQ(data[2], 4);
  ASSERT_EQ(data.size(), 3);

  Array<int> data2;
  data2.push(1);
  data2.push(5);
  data2.push(4);
  ASSERT_TRUE(data == data2);

  data2.push(5);
  ASSERT_FALSE(data == data2);

  data.clear();
  ASSERT_EQ(data.size(), 0);
}
