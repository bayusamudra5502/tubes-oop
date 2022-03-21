#include <gtest/gtest.h>

#include <Map.hpp>
#include <exception/BaseException.hpp>
#include <exception/KeyNotFound.hpp>
#include <string>

using namespace std;

TEST(MAP_TEST, MAP_INSERT_1) {
  Map<int, int> m;
  m.insertItem(0, 20);
  m.insertItem(8, 20);
  m.insertItem(6, 90);

  ASSERT_TRUE(m.isKeyExist(0));
  ASSERT_TRUE(m.isKeyExist(6));
  ASSERT_TRUE(m.isKeyExist(8));

  ASSERT_FALSE(m.isKeyExist(2));
  ASSERT_FALSE(m.isKeyExist(3));
}

TEST(MAP_TEST, MAP_INSERT_2) {
  Map<string, int> m;
  m.insertItem("hehe", 20);
  m.insertItem("hoho", 90);
  m.insertItem("haha", 20);

  ASSERT_TRUE(m.isKeyExist("haha"));
  ASSERT_TRUE(m.isKeyExist("hehe"));
  ASSERT_TRUE(m.isKeyExist("hoho"));

  ASSERT_FALSE(m.isKeyExist("yu"));
  ASSERT_FALSE(m.isKeyExist("opa"));
}

TEST(MAP_TEST, MAP_ISI) {
  Map<int, int> m;
  m.insertItem(1, 20);
  m.insertItem(10, 90);
  m.insertItem(100, 20);

  ASSERT_EQ(m[1], 20);
  ASSERT_EQ(m[10], 90);
  ASSERT_EQ(m[100], 20);
}

TEST(MAP_TEST, MAP_ISI_NOT_FOUND) {
  Map<int, int> m;
  m.insertItem(1, 20);
  m.insertItem(10, 90);
  m.insertItem(100, 20);

  ASSERT_THROW(m[20], BaseException*);
  ASSERT_THROW(m[20], KeyNotFound<int>*);
}
