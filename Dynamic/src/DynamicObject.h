#pragma once

#include <iostream>

class DynamicObject {
	public:
		DynamicObject() {}
		~DynamicObject() {}
		virtual bool init() = 0;
		virtual void update() = 0;
};
