#include <exception/SlotOverflow.hpp>
#include <sstream>

SlotOverflow::SlotOverflow(int mxSize, int sz) : BaseException("Slot Overflow Exception"){
    this->mxSize = mxSize;
    this->sz = sz;
}

string SlotOverflow::what(){
    string s;
    stringstream ss(s);
    ss << this->getErrorName() << " has occured! The available slot is " << this->mxSize << " item(s), but you inserted " << this->sz << " item(s).";
    return s;
}
