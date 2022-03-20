#include <Item.hpp>

Item::Item(const Item& other) {
  this->name = other.name;
  this->mxStack = other.mxStack;
}

bool Item::operator==(const Item& other) { return (this->name == other.name); }

bool Item::operator<(const Item& other) { return (this->name < other.name); }

bool Item::operator>(const Item& other) { return (this->name > other.name); }

bool Item::operator!=(const Item& other) { return (this->name != other.name); }

Item& Item::operator=(const Item& other) {
  this->name = other.name;
  this->mxStack = other.mxStack;
  return *this;
}

int Item::getMaxStack() { return this->mxStack; }

string NonToolItem::getName() { return this->name; }

string ToolItem::getName() { return this->name; }

void ToolItem::useItem() {
  this->health--;
  if (this->health == 0) {
  }
}