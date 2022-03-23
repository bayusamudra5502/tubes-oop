#include <exception/BaseException.hpp>

BaseException::BaseException() {
  this->errorName = "Exception";
  this->errorDetail = NULL;
}

BaseException::BaseException(string errorName) {
  this->errorName = errorName;
  this->errorDetail = NULL;
}

BaseException::~BaseException() {}

string BaseException::getErrorName() const { return this->errorName; }

const void* BaseException::detail() const { return this->errorDetail; }