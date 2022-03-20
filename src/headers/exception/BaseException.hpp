#pragma once
#include <string>
using namespace std;

class BaseException {
 private:
  string errorName;

 public:
  BaseException();
  BaseException(string errorName);
  string getErrorName();
  virtual void* detail() = 0;
};