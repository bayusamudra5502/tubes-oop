#pragma once

#include <exception/BaseException.hpp>

class IndexOutBondCC: public BaseException {
    protected:
        int mxRow;
        int mxCol;

    public:
        IndexOutBondCC(int mxRow, int mxCol);
        virtual string what();
};