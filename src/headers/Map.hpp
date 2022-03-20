#pragma once

#include <utility>
#include <vector>
using namespace std;

template <class T, class U>
class Map {
 private:
  vector<pair<T, U>> data;
  pair<int, bool> getPosition(T key);

 public:
  U& operator[](T key);
  U getItem(T key);
  void insertItem(T key, U value);
  void deleteItem(T key);
  bool isKeyExist(T key);
};