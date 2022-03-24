#include <gtest/gtest.h>

#include <Item.hpp>
#include <NonToolItem.hpp>
#include <Slot.hpp>
#include <ToolItem.hpp>

TEST(SLOT_TEST, SLOT_EQUALITY) {
  Item* i1 = new ToolItem(1, "DIAMOND SWORD");
  Item* i2 = new ToolItem(2, "WOODEN SWORD");
  Item* i3 = new NonToolItem(3, "OAK PLANK", "PLANK");
  Item* i4 = new NonToolItem(4, "BIRCH PLANK", "PLANK");
  Item* i5 = new NonToolItem(-2, "*", "PLANK");
  Item* i6 = new NonToolItem(-2, "*", "WOOD");
  Item* i7 = new ToolItem(1, "DIAMOND SWORD");
  Item* i8 = new NonToolItem(3, "OAK PLANK", "PLANK");

  Slot s1(1, i1);
  Slot s2(2, i2);
  Slot s3(3, i3);
  Slot s4(4, i4);
  Slot s5(5, i5);
  Slot s6(6, i6);
  Slot s7(6, i7);
  Slot s8(6, i8);

  ASSERT_TRUE(s1 == s7);
  ASSERT_TRUE(s3 == s8);
  ASSERT_TRUE(s3 == s5);
  ASSERT_TRUE(s4 == s5);

  ASSERT_FALSE(s3 == s4);
  ASSERT_FALSE(s1 == s2);
}