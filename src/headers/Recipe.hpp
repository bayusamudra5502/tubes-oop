#pragma once

#include <CollectionContainer.hpp>
#include <CraftingTable.hpp>
#include <Item.hpp>

using namespace std;

class Recipe : private CollectionContainer {
 public:
  Recipe();
  Recipe(int row, int col, Item* item);
  Recipe(int row, int col, vector<Item> item);
  bool operator==(const Recipe& r);
  friend bool operator==(const CraftingTable& ct, const Recipe& r);
  friend bool operator==(const Recipe& r, const CraftingTable& ct);
};