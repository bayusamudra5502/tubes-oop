#include <exception/BaseException.hpp>

BaseException::BaseException() { this->errorName = "Exception"; }

BaseException::BaseException(string errorName) { this->errorName = errorName; }

string BaseException::getErrorName() { return this->errorName; }