#pragma once

#include <exception/BaseException.hpp>
#include <iostream>
#include <string>

using namespace std;

template <class T>
struct KeyNotFoundDetail {
  T key;
};

template <class T>
class KeyNotFound : public BaseException {
 private:
  struct KeyNotFoundDetail<T> detailObject;

 public:
  KeyNotFound(T key);
  void *detail();
};

template <class T>
KeyNotFound<T>::KeyNotFound(T key) : BaseException("MapKeyNotFound") {
  this->detailObject.key = key;
}

template <class T>
void *KeyNotFound<T>::detail() {
  return (void *)&(this->detailObject);
}
