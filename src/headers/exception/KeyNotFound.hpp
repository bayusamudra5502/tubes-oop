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
  virtual string what();
};

template <class T>
KeyNotFound<T>::KeyNotFound(T key) : BaseException("MapKeyNotFound") {
  KeyNotFoundDetail<T>* errorDetail = new KeyNotFoundDetail<T>{key};
  this->errorDetail = errorDetail;
}

template <class T>
string KeyNotFound<T>::what() {
  KeyNotFoundDetail<T>* errorDetail = (KeyNotFoundDetail<T>*)this->errorDetail;
  string s = "Map key '" + errorDetail->key + "' is not found.";
  return s;
}