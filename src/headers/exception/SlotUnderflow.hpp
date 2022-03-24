#pragma once

#include <exception/BaseException.hpp>

class SlotUnderflow : public BaseException {
    protected:
        int sz;
        int discard;
    public:
        SlotUnderflow(int sz, int discard);
        virtual string what();
};