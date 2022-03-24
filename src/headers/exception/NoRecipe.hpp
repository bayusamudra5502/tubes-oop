#pragma once

#include <CraftingTable.hpp>
#include <exception/BaseException.hpp>

class NoRecipe : public BaseException {
 public:
  NoRecipe();
  virtual string what();
};