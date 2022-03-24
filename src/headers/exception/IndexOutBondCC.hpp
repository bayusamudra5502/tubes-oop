#pragma once

#include <exception/BaseException.hpp>

class IndexOutBondCC: public BaseException {
    protected:
        int mxRow;
        int mxCol;
        int curRow;
        int curCol;

    public:
        IndexOutBondCC(int mxRow, int mxCol, int curRow, int curCol);
        virtual string what();
};