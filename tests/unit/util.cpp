#include <gtest/gtest.h>

#include <util.hpp>

TEST(UTIL_TEST, EXTRACT_ID) {
  vector<struct InventoryMap> result;
  vector<struct InventoryMap> expected;

  result.push_back(extractId("I123", 10));
  expected.push_back({'I', 12, 3});

  result.push_back(extractId("A12", 9));
  expected.push_back({'A', 1, 3});

  result.push_back(extractId("Z0", 9));
  expected.push_back({'Z', 0, 0});

  for (int i = 0; i < (int)result.size(); i++) {
    ASSERT_EQ(result[i], expected[i]);
  }
}