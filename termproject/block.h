#include <iostream>
;
using namespace std;
class block {
	int color = 0;
	int y = 0;
	int x = 0;
public:
	block(int x,int y, int color) {
		this->x = x;
		this->y = y;
		this->color = color;
	}
	block() {
		
	}
	int get_color() {
		return this->color;
	}
	int get_xLocation() {
		return this->x;
	}
	int get_yLocation() {
		return this->y;
	}
	void set_color(int c) {
		this->color = c;
	}
	void set_location(int y, int x) {
		this->y = y;
		this->x = x;
	}
	bool can_down(int board[][5]) {
		if (board[this->y + 1][x] != 0) {
			return false;
		}
		else if (this->y >= 11) {
			return false;
		}
		return true;
	}
	bool can_right(int board[][5]) {
		if (board[this->y][x+1] != 0) {
			return false;
		}
		else if (this->x >= 4) {
			return false;
		}
		return true;
	}
	bool can_left(int board[][5]) {
		if (board[this->y][x - 1] != 0) {
			return false;
		}
		else if (this->x <= 0) {
			return false;
		}
		return true;
	}
};
