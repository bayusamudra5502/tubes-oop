#pragma once

#include <CollectionContainer.hpp>
#include <CraftingTable.hpp>
#include <Slot.hpp>

using namespace std;

class Recipe : private CollectionContainer {
 private:
  Slot result;

 public:
  Recipe();
  Recipe(int row, int col, vector<Slot> item, Slot result);
  bool operator==(const Recipe& r);
  Slot getResult() const;
  friend bool operator==(const CraftingTable& ct, const Recipe& r);
  friend bool operator==(const Recipe& r, const CraftingTable& ct);
};