#include <command.hpp>
#include <exception/UseNonToolItem.hpp>
#include <util.hpp>

void doUse(Inventory& inventory) {
  string location;
  cin >> location;
  if(location[0]!='C'&&location[0]!='I'){
    throw new WrongCommandException(INVALID_PARAMETER);
  }
  struct InventoryMap map = extractId(location, MAX_INVENTORY_COL);
  inventory.useItem(map.row, map.col);
  if(dynamic_cast<ToolItem*>(inventory[{map.row, map.col}].get_contents())->getHealth()==0){
    inventory.deleteItem({map.row, map.col});
  }
}