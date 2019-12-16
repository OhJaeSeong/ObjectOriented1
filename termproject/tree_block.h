#include <iostream>
;
class tree_block {
public:
	block tb1;
	block tb2;
	block tb3;

	tree_block(block tc1, block tc2, block tc3) {
		this->tb1 = block(tc1.get_xLocation(), tc1.get_yLocation(), tc1.get_color());
		this->tb2 = block(tc2.get_xLocation(), tc2.get_yLocation(), tc2.get_color());
		this->tb3 = block(tc3.get_xLocation(), tc3.get_yLocation(), tc3.get_color());
	}

	void go_down() {
		this->tb1.set_location(this->tb1.get_yLocation() + 1, this->tb1.get_xLocation());
		this->tb2.set_location(this->tb2.get_yLocation() + 1, this->tb2.get_xLocation());
		this->tb3.set_location(this->tb3.get_yLocation() + 1, this->tb3.get_xLocation());
	}
	void go_left() {
		this->tb1.set_location(this->tb1.get_yLocation(), this->tb1.get_xLocation() - 1);
		this->tb2.set_location(this->tb2.get_yLocation(), this->tb2.get_xLocation() - 1);
		this->tb3.set_location(this->tb3.get_yLocation(), this->tb3.get_xLocation() - 1);
	}
	void go_right() {
		this->tb1.set_location(this->tb1.get_yLocation(), this->tb1.get_xLocation() + 1);
		this->tb2.set_location(this->tb2.get_yLocation(), this->tb2.get_xLocation() + 1);
		this->tb3.set_location(this->tb3.get_yLocation(), this->tb3.get_xLocation() + 1);
	}
	bool can_down(int board[][5]) {
		if ((board[this->tb3.get_yLocation() + 1][this->tb3.get_xLocation()] != 0)) {
			return false;
		}
		else if (this->tb3.get_yLocation() >= 11 ||
			this->tb2.get_yLocation() >= 11 ||
			this->tb1.get_yLocation() >= 11
			) {
			return false;
		}
		else {
			return true;
		}
	}
	bool can_right(int board[][5]) {
		if ((board[this->tb1.get_yLocation()][this->tb1.get_xLocation() + 1] != 0) ||
			(board[this->tb2.get_yLocation()][this->tb2.get_xLocation() + 1] != 0) ||
			(board[this->tb3.get_yLocation()][this->tb3.get_xLocation() + 1] != 0)
			) {
			return false;
		}
		else if (this->tb2.get_xLocation() >= 4 ||
			this->tb1.get_xLocation() >= 4 ||
			this->tb3.get_xLocation() >= 4
			) {
			return false;
		}
		return true;
	}
	bool can_left(int board[][5]) {
		if ((board[this->tb1.get_yLocation()][this->tb1.get_xLocation() - 1] != 0) ||
			(board[this->tb2.get_yLocation()][this->tb2.get_xLocation() - 1] != 0) ||
			(board[this->tb3.get_yLocation()][this->tb3.get_xLocation() - 1] != 0)
			) {
			return false;
		}
		else if (this->tb1.get_xLocation() <= 0 ||
			this->tb2.get_xLocation() <= 0 ||
			this->tb3.get_xLocation() <= 0
			) {
			return false;
		}
		return true;
	}
};