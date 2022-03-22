#pragma once

#include <Item.hpp>
#include <Map.hpp>
#include <Recipe.hpp>
#include <Slot.hpp>

class RecipeBook {
 private:
 public:
  void insert(const Recipe& r);
  Slot find(const CraftingTable& ct);
};