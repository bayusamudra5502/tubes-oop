#pragma once

#include <exception/BaseException.hpp>

typedef enum WrongType { INVALID_PARAMETER, INVALID_COMMAND } WrongType;
class WrongCommandException : public BaseException {
    protected:
        WrongType w;
    public:
        WrongCommandException(WrongType w);
        virtual string what();
};