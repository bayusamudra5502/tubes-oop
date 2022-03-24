#include <command.hpp>


void doCraft(CraftingTable& crafting, Inventory& inventory, RecipeBook recipes){
    CraftingTable tempC(crafting);
    Inventory tempI(inventory);
    try{
        Slot res = recipes.find(crafting);
        crafting.craft();
        inventory.giveItem(res.get_contents(), 1);
    }catch(BaseException* e){
        crafting = tempC;
        inventory = tempI;
        throw e;
    }
}