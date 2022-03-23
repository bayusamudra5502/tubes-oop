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
  void insert(const Recipe& r);
  Slot find(const CraftingTable& ct);
};