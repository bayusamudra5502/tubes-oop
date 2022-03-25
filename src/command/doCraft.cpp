#include <command.hpp>

void doCraft(CraftingTable& crafting, Inventory& inventory,
             RecipeBook recipes) {
  CraftingTable tempC(crafting);
  Inventory tempI(inventory);
  try {
    Slot res = recipes.find(crafting);
    crafting.craft();
    inventory.giveItem(res.get_contents(), res.get_occupied());
    cout << "\nCongratulations! You crafted \x1B[33m" << res.get_occupied()
         << "\x1B[0m item(s) of \x1B[36m" << res.get_contents()->getName()
         << "\x1B[0m\n\n";
  } catch (BaseException* e) {
    crafting = tempC;
    inventory = tempI;
    throw e;
  }
}

void doMultiCraft(CraftingTable& crafting, Inventory& inventory,
                  RecipeBook recipes) {
  int i = 0;
  while (true) {
    try {
      doCraft(crafting, inventory, recipes);
    } catch (BaseException* e) {
      if (i == 0) {
        throw e;
      } else {
        break;
      }
    }
    i++;
  }
}