#include <exception/IndexOutBondCC.hpp>
#include <sstream>

IndexOutBondCC::IndexOutBondCC(int mxRow, int mxCol, int curRow, int curCol) : BaseException("Index out of bond in Collection Container") {
    this -> mxRow = mxRow;
    this -> mxCol = mxCol;
    this -> curRow = curRow;
    this -> curCol = curCol;
}

string IndexOutBondCC::what() {
    stringstream ss;
    ss << this->getErrorName() << " has occured! the maximum capacity is (" << this->mxRow << ", " << this->mxCol << "), but you inserted (" << this->curRow << ", " << this->curCol << ").";
    return ss.str();
}