#include <exception/KeyNotFound.hpp>
#include <iostream>
using namespace std;

template <class T>
KeyNotFound<T>::KeyNotFound(T key) : BaseException("MapKeyNotFound") {
  this->detailObject.key = key;
}

template <class T>
void* KeyNotFound<T>::detail() {
  return (void*)&(this->detailObject);
}