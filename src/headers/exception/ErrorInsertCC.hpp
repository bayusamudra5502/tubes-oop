#pragma once

#include <exception/BaseException.hpp>

class ErrorInsertCC: public BaseException {
    protected:
        int mxRow;
        int mxCol;

    public:
        ErrorInsertCC(int mxRow, int mxCol);
        virtual string what();
};