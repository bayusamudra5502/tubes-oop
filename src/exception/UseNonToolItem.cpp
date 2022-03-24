#include <exception/UseNonToolItem.hpp>
#include <sstream>

UseNonToolItem::UseNonToolItem(ItemType type) : BaseExceptionBaseException("Error using non tool item") {
	this-> type = type;
}

string UseNonToolItem::what(){
	string s;
    stringstream ss(s);
    ss << this->getErrorName() << " has occured! A non tool item cannot call UseItem() method";
    return s;
}