#include <exception/InventoryOverflow.hpp>
#include <sstream>

InventoryOverflow::InventoryOverflow(string itemName, int qty): BaseException("Inventory Overflow"){
    this->itemName = itemName;
    this->qty = qty;
}
string InventoryOverflow::what(){
    stringstream ss;
    ss << this->getErrorName() << "! Your inventory cannot hold item " << this->itemName << " anymore, space needed is " << this->qty << ".";
    return ss.str();
}