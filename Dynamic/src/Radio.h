#pragma once

#include <iostream>
#include <string>

#include "DynamicObject.h"

class Radio : DynamicObject {
	private:
		std::string m_current_track;
	public:
		Radio();
		~Radio();

		bool init();
		void update();
		
		void play_audio();
		std::string get_current_track();
};
