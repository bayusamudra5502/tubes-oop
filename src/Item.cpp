#include <Item.hpp>

Item::Item(const Item& other) {
  this->metadata = other.metadata;
  this->mxStack = other.mxStack;
}

Item::Item() {}

Item::Item(const ItemMetadata& data) {
  this->metadata = data;

  if (data.type == NONTOOLS) {
    this->mxStack = 1;
  } else {
    this->mxStack = 64;
  }
}

bool Item::operator==(const Item& other) {
  return (this->metadata.itemId == other.metadata.itemId);
}

bool Item::operator<(const Item& other) {
  return (this->metadata.itemId < other.metadata.itemId);
}

bool Item::operator>(const Item& other) {
  return (this->metadata.itemId > other.metadata.itemId);
}

bool Item::operator!=(const Item& other) {
  return (this->metadata.itemId != other.metadata.itemId);
}

Item& Item::operator=(const Item& other) {
  this->metadata = metadata;
  this->mxStack = other.mxStack;
  return *this;
}

int Item::getMaxStack() const { return this->mxStack; }

string Item::getName() const { return this->metadata.name; }

string NonToolItem::getCategory() const { return this->metadata.category; }

void ToolItem::useItem() {
  if (this->health > 0) {
    this->health--;
  }
}

void ToolItem::setHealth(int newHealth) { this->health = newHealth; }