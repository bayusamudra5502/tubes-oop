#pragma once
#include <Slot.hpp>

struct Position {
  int row, col;
};

class CollectionContainer {
 protected:
  vector<vector<Slot>> container;
  int mxRow;  // banyak baris
  int mxCol;  // banyak kolom

 public:
  // constructor
  CollectionContainer();
  CollectionContainer(int mxRow, int mxCol);

  // copy constructor
  CollectionContainer(const CollectionContainer &cc);

  // destructor
  ~CollectionContainer();

  // operator
  CollectionContainer &operator=(CollectionContainer &cc);

  bool operator==(CollectionContainer &cc);
  Slot operator[](const Position &pos) const;

  void insertItem(Position p, Item* item, int count = 1);
  void deleteItem(Position p, int count = 1);

  bool isEmpty(Position p) const;


  friend ostream &operator<<(ostream &stream, const CollectionContainer &cc);
};
