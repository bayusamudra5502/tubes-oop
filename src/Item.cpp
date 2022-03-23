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

NonToolItem::NonToolItem() : Item() { this->category = "NULL"; }

NonToolItem::NonToolItem(const NonToolItem& copy) : Item(copy) {}

NonToolItem::NonToolItem(int itemId, string name, string category)
    : Item(itemId, name, NONTOOLS, MXNONTOOL) {
  this->category = category;
}

NonToolItem::~NonToolItem() {}

string NonToolItem::getCategory() const { return this->category; }

NonToolItem& NonToolItem::operator=(const NonToolItem& other) {
  Item::operator=(other);
  this->category = other.category;
  return *this;
}

int Item::getNameLength() { return this->getName().size(); }

void Item::print(ostream& s, int mxLength) {
  s << this->name;
  for (int i = this->getNameLength(); i < mxLength; i++) {
    s << " ";
  }
}

ToolItem& ToolItem::operator=(const ToolItem& other) {
  Item::operator=(other);
  this->health = health;
  return *this;
}

ToolItem::ToolItem() : Item() { this->health = 10; }

ToolItem::ToolItem(const ToolItem& copy) : Item(copy) {}

ToolItem::ToolItem(int itemId, string name)
    : Item(itemId, name, TOOLS, MXTOOL) {
  this->health = 10;
}

ToolItem::~ToolItem() {}

void ToolItem::useItem() {
  if (this->health > 0) {
    this->health--;
  }
}

int ToolItem::getHealth() const { return this->health; }

void ToolItem::setHealth(int newHealth) { this->health = newHealth; }

int ToolItem::getNameLength() {
  int cnt = 0;
  if (this->getHealth() < 10) {
    cnt = 1;
  } else {
    cnt = 2;
  }
  cnt += this->getName().size() + 3;
  return cnt;
}

void ToolItem::print(ostream& s, int mxLength) {
  s << this->name << " (" << this->getHealth() << ")";
  for (int i = this->getNameLength(); i < mxLength; i++) {
    s << " ";
  }
}