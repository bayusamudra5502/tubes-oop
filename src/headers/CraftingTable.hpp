#pragma once
#include <CollectionContainer.hpp>

class Recipe;

class CraftingTable : public CollectionContainer {
 public:
  CraftingTable();
  friend bool operator==(const CraftingTable& ct, const Recipe& r);
  friend bool operator==(const Recipe& r, const CraftingTable& ct);
};