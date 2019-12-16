#include <iostream>
;
class fold_block {
public:
	block fb1;
	block fb2;
	block fb3;

	fold_block(block fc1, block fc2, block fc3) {
		this->fb1 = block(fc1.get_xLocation(), fc1.get_yLocation(), fc1.get_color());
		this->fb2 = block(fc2.get_xLocation(), fc2.get_yLocation(), fc2.get_color());
		this->fb3 = block(fc3.get_xLocation(), fc3.get_yLocation(), fc3.get_color());
	}
	void go_down() {
		this->fb1.set_location(this->fb1.get_yLocation() + 1, this->fb1.get_xLocation());
		this->fb2.set_location(this->fb2.get_yLocation() + 1, this->fb2.get_xLocation());
		this->fb3.set_location(this->fb3.get_yLocation() + 1, this->fb3.get_xLocation());
	}
	void go_left() {
		this->fb1.set_location(this->fb1.get_yLocation(), this->fb1.get_xLocation() - 1);
		this->fb2.set_location(this->fb2.get_yLocation(), this->fb2.get_xLocation() - 1);
		this->fb3.set_location(this->fb3.get_yLocation(), this->fb3.get_xLocation() - 1);
	}
	void go_right() {
		this->fb1.set_location(this->fb1.get_yLocation(), this->fb1.get_xLocation() + 1);
		this->fb2.set_location(this->fb2.get_yLocation(), this->fb2.get_xLocation() + 1);
		this->fb3.set_location(this->fb3.get_yLocation(), this->fb3.get_xLocation() + 1);
	}
	bool can_down(int board[][5]) {
		if ((board[this->fb1.get_yLocation() + 1][this->fb1.get_xLocation()] != 0) ||
			(board[this->fb2.get_yLocation() + 1][this->fb2.get_xLocation()] != 0)
			) {
			return false;
		}
		else if (this->fb2.get_yLocation() > 11 ||
			this->fb1.get_yLocation() > 11
			) {
			return false;
		}
		else {
			return true;
		}
	}
	bool can_right(int board[][5]) {
		if ((board[this->fb2.get_yLocation()][this->fb2.get_xLocation() + 1] != 0) ||
			(board[this->fb3.get_yLocation()][this->fb3.get_xLocation() + 1] != 0)) {
			return false;
		}
		else if (this->fb2.get_xLocation() >= 4 ||
			this->fb1.get_xLocation() >= 4 ||
			this->fb3.get_xLocation() >= 4
			) {
			return false;
		}
		else {
			return true;
		}
	}
	bool can_left(int board[][5]) {
		if ((board[this->fb1.get_yLocation()][this->fb1.get_xLocation() - 1] != 0)) {
			return false;
		}
		else if (this->fb1.get_xLocation()-1 < 0 ||
			this->fb2.get_xLocation() - 1 < 0 ||
			this->fb3.get_xLocation() - 1 < 0
			) {
			return false;
		}
		return true;
	}
}