#include <gtest/gtest.h>

#include <Item.hpp>
#include <Map.hpp>
#include <NonToolItem.hpp>
#include <Slot.hpp>
#include <ToolItem.hpp>
#include <vector>

using namespace std;

TEST(ITEM_DICTIONARY, UJI_DICTIONARY) {
  vector<Slot> vc;
  Map<string, Item*> mi;

  mi.insertItem("Belalang", new NonToolItem(1, "Belalang", "Hewan"));
  mi.insertItem("Kucing", new NonToolItem(2, "Kucing", "Hewan"));
  mi.insertItem("Hewan", new NonToolItem(-2, "*", "Hewan"));
  mi.insertItem("Mobil", new NonToolItem(3, "Mobil", "Kendaraan"));
  mi.insertItem("Sepeda", new NonToolItem(4, "Sepeda", "Kendaraan"));
  mi.insertItem("Kendaraan", new NonToolItem(-2, "*", "Kendaraan"));

  ASSERT_NO_FATAL_FAILURE(vc.push_back(Slot(1, mi["Belalang"])));
  ASSERT_NO_FATAL_FAILURE(vc.push_back(Slot(2, mi["Kucing"])));
  ASSERT_NO_FATAL_FAILURE(vc.push_back(Slot(3, mi["Hewan"])));
  ASSERT_NO_FATAL_FAILURE(vc.push_back(Slot(4, mi["Mobil"])));
  ASSERT_NO_FATAL_FAILURE(vc.push_back(Slot(5, mi["Sepeda"])));
  ASSERT_NO_FATAL_FAILURE(vc.push_back(Slot(6, mi["Kendaraan"])));
}