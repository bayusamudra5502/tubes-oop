#include <Item.hpp>

Item::Item() {
  this->mxStack = 0;
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

int Item::getMaxStack() const { 
    return this->mxStack; 
}

int Item::getItemId() const {
    return this->itemId;
}

ItemType Item::getType() const {
    return this -> type;
}

string Item::getName() const { 
    return this->name; 
}

NonToolItem::NonToolItem() : Item() { 
    this->category = ""; 
}

NonToolItem::NonToolItem(const NonToolItem& copy) : Item(copy) {}

NonToolItem::NonToolItem(int itemId, string name, string category, int maxStack)
    : Item(itemId, name, NONTOOLS, maxStack) {
  this->category = category;
}

string NonToolItem::getCategory() const { return this->category; }

NonToolItem& NonToolItem::operator=(const NonToolItem& other) {
  Item::operator=(other);
  this->category = other.category;
  return *this;
}

ToolItem& ToolItem::operator=(const ToolItem& other) {
  Item::operator=(other);
  this->health = health;
  return *this;
}

ToolItem::ToolItem() : Item() { 
    this->health = 10; 
}

ToolItem::ToolItem(const ToolItem& copy) : Item(copy) {}

ToolItem::ToolItem(int itemId, string name) : Item(itemId, name, TOOLS, 1) {
  this->health = 10;
}

void ToolItem::useItem() {
  if (this->health > 0) {
    this->health--;
  }
}

void ToolItem::setHealth(int newHealth) { this->health = newHealth; }