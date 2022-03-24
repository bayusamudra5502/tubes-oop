#pragma once
#include <exception/BaseException.hpp>

class UseNonToolItem: public BaseException {
	protected:
		ItemType type;
	public:
		UseNonToolItem(ItemType type);
		virtual string what();
};