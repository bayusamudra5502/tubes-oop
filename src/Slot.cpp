#include <Slot.hpp>

Slot::Slot() {
  this->id = 0;
  this->contents = new Item();
  this->available_slot = MXNULL;
  this->occupied = 0;
}

Slot::Slot(int id) {
  this->id = id;
  this->contents = new Item();
  this->available_slot = MXNULL;
  this->occupied = 0;
}

Slot::Slot(int id, Item* item) {
  this->id = id;
  this->contents = item;
  this->available_slot = item->getMaxStack();
  this->occupied = 0;
}

Slot::Slot(int id, Item* item, int used) {
  if (item->getMaxStack() - used < 0) {
    throw new SlotOverflow(item->getMaxStack(), used);
  } else {
    this->id = id;
    this->contents = item;
    this->available_slot = item->getMaxStack() - used;
    this->occupied = used;
  }
}

Slot::Slot(const Slot& other) {
  this->id = other.id;
  this->contents = other.contents->clone();
  this->available_slot = other.available_slot;
  this->occupied = other.occupied;
}

Slot::~Slot() { delete contents; }

Slot& Slot::operator=(Slot& other) {
  this->id = other.id;
  delete this->contents;
  this->contents = other.contents->clone();
  this->available_slot = other.available_slot;
  return *this;
}

bool Slot::empty() const { return this->contents->isEmpty(); }

bool Slot::full() const { return this->available_slot == 0; }

void Slot::insert(Item* item, int count = 1) {
  if (this->empty()) {
    if (item->getMaxStack() - count < 0) {
      throw new SlotOverflow(item->getMaxStack(), count);
    } else {
      this->id = id;
      this->contents = item;
      this->available_slot = item->getMaxStack() - count;
      this->occupied = count;
    }
  } else {
    if (*this->contents != *item) {
      throw new NonCompatibleItem(this->contents, item);
    } else if (this->available_slot < count) {
      throw new SlotOverflow(this->available_slot, count);
    } else {
      this->available_slot -= count;
      this->occupied += count;
    }
  }
}

void Slot::remove(int count = 1) {
  if (this->occupied == count) {
    this->contents = new Item();
    this->occupied = 0;
    this->available_slot = MXNONTOOL;
  } else if (this->occupied < count) {
    throw new SlotUnderflow(this->occupied, count);
  } else {
    this->occupied -= count;
    this->available_slot += count;
  }
}

int Slot::get_id() { return this->id; }

Item* Slot::get_contents() { return this->contents; }

int Slot::get_available_slot() { return this->available_slot; }

int Slot::get_occupied() { return this->occupied; }

void Slot::print(ostream& stream, int mxLen) {
  this->contents->print(stream, mxLen);
  stream << " ";
  if (this->get_occupied() < 10) {
    stream << " ";
  }
  stream << "(" << this->get_occupied() << ")";
}

bool Slot::operator==(const Slot& other) {
  return *this->contents == *other.contents;
}

bool Slot::operator!=(const Slot& other) {
  return *this->contents == *other.contents;
}