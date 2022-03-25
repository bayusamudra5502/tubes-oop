#pragma once
#include <string>
using namespace std;

class BaseException {
 private:
  string errorName;

 protected:
  void* errorDetail;

 public:
  BaseException();
  BaseException(string errorName);
  virtual ~BaseException();
  string getErrorName() const;
  const void* detail() const;

  virtual string what() = 0;
};
