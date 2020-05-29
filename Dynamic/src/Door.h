#pragma once

#include <iostream>
#include <string>

#include "DynamicObject.h"

class Door : DynamicObject {
	private:
		bool m_opened;
	public:
		Door();
		~Door();

		bool init();
		void update();
		
		void open();
		void close();
		bool is_opened();
};
