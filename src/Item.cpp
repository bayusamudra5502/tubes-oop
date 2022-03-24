#include <Item.hpp>

Item::Item() {
  this->name = "KOSONG";
  this->type = NULLITEM;
  this->mxStack = MXNULL;
  this->itemId = -1;
}

Item::Item(int itemId, string name, ItemType type, int maxStack) {
  this->mxStack = maxStack;
  this->itemId = itemId;
  this->name = name;
  this->type = type;
}

Item::Item(const Item& other) {
  this->mxStack = other.mxStack;
  this->itemId = other.itemId;
  this->name = other.name;
  this->type = other.type;
}

Item::~Item() {}

Item* Item::clone() { return new Item(*this); }

bool Item::isEmpty() { return this->type == NULLITEM; }

bool Item::operator==(const Item& other) {
  return (this->itemId == other.itemId);
}

bool Item::operator<(const Item& other) {
  return (this->itemId < other.itemId);
}

bool Item::operator>(const Item& other) {
  return (this->itemId > other.itemId);
}

bool Item::operator!=(const Item& other) {
  return (this->itemId != other.itemId);
}

Item& Item::operator=(const Item& other) {
  this->mxStack = other.mxStack;
  this->itemId = other.itemId;
  this->name = other.name;
  this->type = other.type;
  return *this;
}

int Item::getMaxStack() const { return this->mxStack; }

int Item::getItemId() const { return this->itemId; }

ItemType Item::getType() const { return this->type; }

string Item::getName() const { return this->name; }

int Item::getNameLength() { return this->getName().size(); }

void Item::print(ostream& s, int mxLength) {
  s << this->name;
  for (int i = this->getNameLength(); i < mxLength; i++) {
    s << " ";
  }
}
