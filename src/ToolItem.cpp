#include <ToolItem.hpp>
#include <exception/UseNonToolItem.hpp>

ToolItem& ToolItem::operator=(const ToolItem& other) {
  Item::operator=(other);
  this->health = health;
  return *this;
}

ToolItem::ToolItem() : Item() { this->health = 10; }

ToolItem::ToolItem(const ToolItem& copy) : Item(copy) {
  this->health = copy.health;
}

ToolItem::ToolItem(int itemId, string name)
    : Item(itemId, name, TOOLS, MXTOOL) {
  this->health = 10;
}

ToolItem::~ToolItem() {}

Item* ToolItem::clone() { return new ToolItem(*this); }

void ToolItem::useItem() {
  if (this->health > 0) {
    this->health--;
  }
  if (this->type != TOOLS) {
    throw new UseNonToolItem();
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
  cnt += this->getName().size() + 2;
  return cnt;
}

void ToolItem::print(ostream& s, int mxLength) {
  s << this->name << "(" << this->getHealth() << ")";
  for (int i = this->getNameLength(); i < mxLength; i++) {
    s << " ";
  }
}