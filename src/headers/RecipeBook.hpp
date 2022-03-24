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

 public:
  RecipeBook();
  RecipeBook(const RecipeBook& r);
  RecipeBook& operator=(const RecipeBook& r);
  Slot toolRepair(const CraftingTable& ct) const;
  void insert(const Recipe& r);
  Slot find(const CraftingTable& ct) const;
};