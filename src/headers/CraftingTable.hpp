#pragma once
#include <Inventory.hpp>

class Recipe;

class CraftingTable : public Inventory {
 public:
  CraftingTable();
  CraftingTable(const CraftingTable& ct);
  bool operator==(const CraftingTable& ct);
  virtual Inventory* clone();
  friend bool operator==(const CraftingTable& ct, const Recipe& r);
  friend bool operator==(const Recipe& r, const CraftingTable& ct);
};