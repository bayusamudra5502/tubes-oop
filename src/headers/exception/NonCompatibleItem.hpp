#pragma once

#include <exception/BaseException.hpp>
#include <Item.hpp>

class NonCompatibleItem : public BaseException {
    protected:
        Item* item1;
        Item* item2;
    public:
        NonCompatibleItem(Item* item1, Item* item2);
        virtual string what();
};