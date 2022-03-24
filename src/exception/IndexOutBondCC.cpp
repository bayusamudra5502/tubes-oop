#include <exception/IndexOutBondCC.hpp>
#include <sstream>

IndexOutBondCC::IndexOutBondCC(int mxRow, int mxCol) : BaseException("Index out of bond in Collection Container") {
    this -> mxRow = mxRow;
    this -> mxCol = mxCol;
}

string IndexOutBondCC::what() {
    stringstream ss;
    ss << this->getErrorName() << " has occured! You have inserted a negative input or your input is more than the capacity!";
    return ss.str();
}