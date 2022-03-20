#pragma once

#include <exception/BaseException.hpp>
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
  void* detail();
};