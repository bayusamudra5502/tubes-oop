#pragma once

#include <CraftingTable.hpp>

using namespace std;

class Recipe : private Inventory {
 private:
  Slot result;

 public:
  Recipe();
  Recipe(const Recipe& r);
  Recipe& operator=(const Recipe& r);
  Recipe(int row, int col, vector<Slot> item, Slot result);
  bool operator==(const Recipe& r);
  Slot getResult() const;
  friend bool operator==(const CraftingTable& ct, const Recipe& r);
  friend bool operator==(const Recipe& r, const CraftingTable& ct);
};