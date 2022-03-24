#pragma once
#include <Slot.hpp>
#include <exception/IndexOutBondCC.hpp>
#include <exception/InventoryOverflow.hpp>

struct Position {
  int row, col;
};

class Inventory {
 protected:
  vector<vector<Slot>> container;
  int mxRow;  // banyak baris
  int mxCol;  // banyak kolom
  char Type;

 public:
  // constructor
  Inventory();
  Inventory(int mxRow, int mxCol);
  Inventory(int mxRow, int mxCol, char type);

  // copy constructor
  Inventory(const Inventory &cc);

  // destructor
  ~Inventory();

  // operator
  Inventory &operator=(Inventory &cc);
  int getmxCol();
  bool operator==(Inventory &cc);
  Slot operator[](const Position &pos) const;
  char getType() const;

  void insertItem(Position p, Item *item, int count = 1);
  void deleteItem(Position p, int count = 1);

  bool isEmpty(Position p) const;
  void giveItem(Item * item, int Qty);
  virtual Inventory* clone();
  void moveItem(string id, int N, vector<string> destId, Inventory* dest);

  friend ostream &operator<<(ostream &stream, const Inventory &cc);
  friend ofstream &operator<<(ofstream &stream, const Inventory &cc);
};
