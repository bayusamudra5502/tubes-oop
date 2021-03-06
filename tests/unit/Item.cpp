#include <gtest/gtest.h>

#include <Item.hpp>
#include <NonToolItem.hpp>
#include <ToolItem.hpp>

TEST(ITEM, ITEM_EQUALITY) {
  vector<Item*> i;
  i.push_back(new NonToolItem(1, "BIRCH PLANK", "PLANK"));
  i.push_back(new NonToolItem(1, "BIRCH PLANK", "PLANK"));
  i.push_back(new NonToolItem(2, "OAK PLANK", "PLANK"));
  i.push_back(new ToolItem(3, "DIAMOND SWORD"));
  i.push_back(new ToolItem(3, "DIAMOND SWORD"));
  i.push_back(new ToolItem(4, "WOODEN SWORD"));
  i.push_back(new NonToolItem(-2, "*", "PLANK"));
  i.push_back(new NonToolItem(-2, "*", "WOOD"));

  ASSERT_TRUE(*(i[0]) == *(i[1]));
  ASSERT_TRUE(*(i[3]) == *(i[4]));
  ASSERT_TRUE(*(i[0]) == *(i[6]));
  ASSERT_TRUE(*(i[2]) == *(i[6]));

  ASSERT_FALSE(*(i[0]) == *(i[2]));
  ASSERT_FALSE(*(i[3]) == *(i[0]));
  ASSERT_FALSE(*(i[0]) == *(i[3]));
  ASSERT_FALSE(*(i[3]) == *(i[5]));
  ASSERT_FALSE(*(i[0]) == *(i[7]));

  ASSERT_FALSE(*(i[7]) == *(i[5]));
  ASSERT_FALSE(*(i[7]) == *(i[4]));
}

TEST(ITEM, ITEM_NEQ) {
  vector<Item*> i;
  i.push_back(new NonToolItem(1, "BIRCH PLANK", "PLANK"));
  i.push_back(new NonToolItem(1, "BIRCH PLANK", "PLANK"));
  i.push_back(new NonToolItem(2, "OAK PLANK", "PLANK"));
  i.push_back(new ToolItem(3, "DIAMOND SWORD"));
  i.push_back(new ToolItem(3, "DIAMOND SWORD"));
  i.push_back(new ToolItem(4, "WOODEN SWORD"));
  i.push_back(new NonToolItem(-2, "*", "PLANK"));
  i.push_back(new NonToolItem(-2, "*", "WOOD"));

  ASSERT_FALSE(*(i[0]) != *(i[1]));
  ASSERT_FALSE(*(i[3]) != *(i[4]));
  ASSERT_FALSE(*(i[0]) != *(i[6]));
  ASSERT_FALSE(*(i[2]) != *(i[6]));

  ASSERT_TRUE(*(i[0]) != *(i[2]));
  ASSERT_TRUE(*(i[3]) != *(i[0]));
  ASSERT_TRUE(*(i[0]) != *(i[3]));
  ASSERT_TRUE(*(i[3]) != *(i[5]));
  ASSERT_TRUE(*(i[0]) != *(i[7]));

  ASSERT_TRUE(*(i[7]) != *(i[5]));
  ASSERT_TRUE(*(i[7]) != *(i[4]));
}