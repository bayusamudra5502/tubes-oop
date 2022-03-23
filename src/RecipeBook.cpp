#include <RecipeBook.hpp>
#include <exception/NoRecipe.hpp>

Slot RecipeBook::find(const CraftingTable& ct) {
  for (auto i : this->db) {
    if (ct == i) {
      return i.getResult();
    }
  }

  throw new NoRecipe();
}
