#include "NonToolItem.hpp"

NonToolItem::NonToolItem() : Item() { this->category = "NULL"; }

NonToolItem::NonToolItem(const NonToolItem& copy) : Item(copy) {
  this->category = copy.category;
}

NonToolItem::NonToolItem(int itemId, string name, string category)
    : Item(itemId, name, NONTOOLS, MXNONTOOL) {
  this->category = category;
}

NonToolItem::~NonToolItem() {}

Item* NonToolItem::clone() { return new NonToolItem(*this); }

string NonToolItem::getCategory() const { return this->category; }

NonToolItem& NonToolItem::operator=(const NonToolItem& other) {
  Item::operator=(other);
  this->category = other.category;
  return *this;
}

bool NonToolItem::operator==(const Item& other) {
  if (other.getType() != this->getType()) {
    return false;
  } else if (other.getItemId() == CATEGORY_ID ||
             this->getItemId() == CATEGORY_ID) {
    const NonToolItem& o = dynamic_cast<const NonToolItem&>(other);
    string thisCategory = this->getCategory();
    return o.getCategory() == thisCategory;
  } else if (Item::operator==(other)) {
    return true;
  }

  return false;
}

bool NonToolItem::operator!=(const Item& other) { return !((*this) == other); }