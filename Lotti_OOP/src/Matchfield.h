#pragma once

#define NO_HOLE -1
#define POS_DEAD -1
#define CARROT_POS 25

class Matchfield {
	private:
		int hole_pos[11] = {NO_HOLE, 13, 25, 16, 23, 4, 21, 7, 19, 10};
		int current_hole;
		bool occupied[CARROT_POS];

	public:
		Matchfield();
		~Matchfield() = default;

		bool is_occupied(int idx);
		void set_occupied(int idx, bool occu);
		
		int get_hole_pos();
		void turn_carrot();
		
};
