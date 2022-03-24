#include <exception/NonCompatibleItem.hpp>
#include <sstream>

NonCompatibleItem::NonCompatibleItem(Item* item1, Item* item2): BaseException("Item Non Compatible"){
    this->item1 = item1->clone();
    this->item2 = item2->clone();
}

string NonCompatibleItem::what(){
    stringstream ss;
    ss << this->getErrorName() << "! " << item1->getName() << " not compatible with " << item2->getName();
    return ss.str();
}