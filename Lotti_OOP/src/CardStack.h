#pragma once

#include <cstdlib>
#include <ctime>

class CardStack {
	public:
		static const int SPIN = 0;
		static const int ONE = 1;
		static const int TWO = 2;
		static const int THREE = 3;
		
		CardStack();
		~CardStack() = default;
		int draw();
};
