#include <RecipeBook.hpp>
#include <exception/NoRecipe.hpp>

Slot RecipeBook::find(const CraftingTable& ct) const {
  for (auto i : this->db) {
    if (ct == i) {
      return i.getResult();
    }
  }

  throw new NoRecipe();
}

void RecipeBook::insert(const Recipe& r) { this->db.push_back(r); }