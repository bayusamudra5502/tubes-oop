#include <exception/ErrorInsertCC.hpp>
#include <sstream>

ErrorInsertCC::ErrorInsertCC(int mxRow, int mxCol) : BaseException("Error insert method in Collection Container") {
    this -> mxRow = mxRow;
    this -> mxCol = mxCol;
}

string ErrorInsertCC::what() {
    string s;
    stringstream ss(s);
    ss << this->getErrorName() << " has occured! You have inserted a negative input or your input is more than the capacity!";
    return s;
}