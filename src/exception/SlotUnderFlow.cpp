#include <exception/SlotUnderflow.hpp>
#include <sstream>

SlotUnderflow::SlotUnderflow(int sz, int discard): BaseException("Slot Underflow"){
    this->sz;
    this->discard = discard;
}

string SlotUnderflow::what(){
    string s;
    stringstream ss(s);
    ss << this->getErrorName() << " has occured! The current quantity is " << this->sz << " item(s), but you deleted " << this->discard << " item(s).";
    return s;
}