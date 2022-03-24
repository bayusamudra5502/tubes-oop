#pragma once
#include <exception/BaseException.hpp>

class UseNonToolItem: public BaseException {
	public:
		UseNonToolItem();
		virtual string what();
};