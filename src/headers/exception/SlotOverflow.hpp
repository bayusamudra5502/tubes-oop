#pragma once

#include <exception/BaseException.hpp>

class SlotOverflow : public BaseException {
    protected:
        int mxSize;
        int sz;
    public:
        SlotOverflow(int mxSize, int sz);
        virtual string what();
};