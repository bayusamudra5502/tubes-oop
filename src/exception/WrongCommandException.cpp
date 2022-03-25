#include <exception/WrongCommandException.hpp>
#include <sstream>

WrongCommandException::WrongCommandException(WrongType w):BaseException("Invalid Command"){
    this->w = w;
}

string WrongCommandException::what(){
    stringstream ss;
    ss << this->getErrorName() << "! Your input " << (this->w==INVALID_COMMAND?"command":"parameter") << " is invalid.";
    return ss.str();
}