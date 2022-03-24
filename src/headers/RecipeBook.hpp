#pragma once

#include <Item.hpp>
#include <Map.hpp>
#include <Recipe.hpp>
#include <Slot.hpp>
#include <vector>

using namespace std;

class RecipeBook {
 private:
  vector<Recipe> db;
  bool isToolRepair(const CraftingTable& ct) const;
  Slot getRepairedTools(const CraftingTable& ct) const;

 public:
  RecipeBook();
  RecipeBook(const RecipeBook& r);
  RecipeBook& operator=(const RecipeBook& r);
  void insert(const Recipe& r);
  Slot find(const CraftingTable& ct) const;
};