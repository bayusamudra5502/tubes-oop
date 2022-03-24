#include <command.hpp>

void doCraft(CraftingTable& crafting, Inventory& inventory,
             RecipeBook recipes) {
  CraftingTable tempC(crafting);
  Inventory tempI(inventory);
  try {
    Slot res = recipes.find(crafting);
    crafting.craft();
    inventory.giveItem(res.get_contents(), res.get_occupied());
  } catch (BaseException* e) {
    crafting = tempC;
    inventory = tempI;
    throw e;
  }
}

void doMultiCraft(CraftingTable& crafting, Inventory& inventory, RecipeBook recipes){  
  int i = 0;
  while(true){
    try {
      doCraft(crafting, inventory, recipes);
    } catch (BaseException* e) {
      if(i==0){
        throw e;
      }
      else{
        break;
      }
    }
    i++;
  }
}