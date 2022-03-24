#pragma once
#include <NonToolItem.hpp>
#include <ToolItem.hpp>

class Slot {
 private:
  int id;
  Item* contents;
  int available_slot;
  int occupied;

 public:
  Slot();
  Slot(int id);
  Slot(int id, Item* item);
  Slot(int id, Item* item, int used);
  Slot(const Slot& other);
  ~Slot();
  Slot& operator=(Slot& other);
  bool operator==(const Slot& other);
  bool operator!=(const Slot& other);


  bool empty() const;
  bool full() const;
  void insert(Item* item, int count);
  void remove(int count);

  int get_id();
  Item* get_contents();
  int get_available_slot();
  int get_occupied();

  void print(ostream& stream, int mxLen);
};