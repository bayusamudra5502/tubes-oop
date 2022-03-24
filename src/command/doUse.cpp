#include <command.hpp>
#include <exception/UseNonToolItem.hpp>
#include <util.hpp>

void doUse(Inventory& inventory) {
  string location;
  cin >> location;

  struct InventoryMap map = extractId(location, MAX_INVENTORY_COL);
  inventory.useItem(map.row, map.col);
  if(dynamic_cast<ToolItem*>(inventory[{map.row, map.col}].get_contents())->getHealth()==0){
    inventory.deleteItem({map.row, map.col});
  }
}