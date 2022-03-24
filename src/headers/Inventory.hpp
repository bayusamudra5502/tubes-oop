#pragma once
#include <CollectionContainer.hpp>

class Inventory : public CollectionContainer {
  public:
    // constructor
    Inventory();

    // copy constructor
    Inventory(const Inventory &inv);

    // destructor
    ~Inventory();
    Inventory &operator=(const Inventory &inv);
    bool operator==(const Inventory &inv);
    Slot operator[](const Position &pos) const;
    char getType() const;
    void insertItem(Position p, Item* item, int count = 1);
    void deleteItem(Position p, int count = 1);
    bool isEmpty(Position p) const;
};