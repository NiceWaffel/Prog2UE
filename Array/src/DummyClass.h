#pragma once

class Dummy {
	public:
		int dummy_int;
		float dummy_float;

		Dummy() = default;
		Dummy(int n) {
			dummy_int = n;
		}

		int dummy_function() {
			return dummy_int;
		}
};
