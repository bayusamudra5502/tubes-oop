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
 public:
  KeyNotFound(T key);
  ~KeyNotFound() { delete (KeyNotFoundDetail<T>*)(this->errorDetail); }
  virtual ostream& printError(ostream& os);
};

template <class T>
KeyNotFound<T>::KeyNotFound(T key) : BaseException("MapKeyNotFound") {
  KeyNotFoundDetail<T>* errorDetail = new KeyNotFoundDetail<T>{key};
  this->errorDetail = errorDetail;
}

template <class T>
ostream& KeyNotFound<T>::printError(ostream& os) {
  KeyNotFoundDetail<T>* errorDetail = (KeyNotFoundDetail<T>*)this->errorDetail;
  os << "Map key '" << errorDetail->key << "' is not found.";

  return os;
}