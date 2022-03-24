#include <exception/UseNonToolItem.hpp>
#include <sstream>

UseNonToolItem::UseNonToolItem() : BaseException("Error using non tool item") {
}

string UseNonToolItem::what(){
    stringstream ss;
    ss << this->getErrorName() << " has occured! A non tool item cannot call UseItem() method";
    return ss.str();
}