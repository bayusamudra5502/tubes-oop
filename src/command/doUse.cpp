#include <command.hpp>
#include <exception/UseNonToolItem.hpp>
#include <util.hpp>

void doUse(Inventory& inventory) {
  string location;
  int count;
  cin >> location >> count;

  try {
    struct InventoryMap map = extractId(location, MAX_INVENTORY_COL);
    inventory.deleteItem({map.col, map.row}, count);
  } catch (IndexOutBondCC* err) {
    cout << "Slot index not found" << endl;
  } catch (SlotUnderflow* err) {
    cout << "Item is not enough" << endl;
  }

  string itemId;
  cin >> itemId;
  struct InventoryMap invmap = extractId(itemId, 9);
  Item* usedItem = inventory[{invmap.row, invmap.col}].get_contents();
  if (usedItem->getType() == TOOLS) {
    ToolItem* toolItem = dynamic_cast<ToolItem*>(usedItem);
    if (toolItem != nullptr) {
      toolItem->useItem();
    }
  } else {
    throw new UseNonToolItem();
  }
}