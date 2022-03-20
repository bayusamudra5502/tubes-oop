#include <Map.hpp>
#include <exception/KeyNotFound.hpp>

template <class T, class U>
U& Map<T, U>::operator[](T key) {
  pair<int, bool> pos = this->getPosition(key);

  if (pos.second) {
    return this->data[pos.first];
  } else {
    throw new KeyNotFound(key);
  }
}

template <class T, class U>
U Map<T, U>::getItem(T key) {
  return *this[key];
}

template <class T, class U>
void Map<T, U>::deleteItem(T key) {
  pair<int, bool> pos = this->getPosition(key);

  if (pos.second) {
    this->data.erase(this->data.begin() + pos.first);
  } else {
    throw new KeyNotFound(key);
  }
}

template <class T, class U>
void Map<T, U>::insertItem(T key, U value) {
  this->data.push_back(make_pair(key, value));
  int i = this->data.size() - 1;

  while (i > 0 && this->data[i] < this->data[i - 1]) {
    swap(this->data.begin() + i, this->data.begin() + i - 1);
    i--;
  }
}

template <class T, class U>
bool Map<T, U>::isKeyExist(T key) {
  return this->getPosition(key).second;
}

template <class T, class U>
pair<int, bool> Map<T, U>::getPosition(T key) {
  int p = 0, q = this->data.size();

  while (this->data[(p + q) / 2].first != key && p < q) {
    if (this->data[(p + q) / 2].first > key) {
      p = (p + q) / 2 + 1;
    } else {
      q = (p + q) / 2;
    }
  }

  if (this->data[(p + q) / 2].first == key) {
    return make_pair((p + q) / 2, true);
  }

  return make_pair(-1, false);
}