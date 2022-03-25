#include <command.hpp>

void doGive(Inventory& inventory, Map<string, Item*> items){
    string itemName;
    int itemQty;
    cin >> itemName >> itemQty;
    if(itemQty<=0){
        throw new WrongCommandException(INVALID_PARAMETER);
    }
    inventory.giveItem(items[itemName], itemQty);
}