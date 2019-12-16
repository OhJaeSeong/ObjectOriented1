#include <iostream>
//using namespace std;
;
class cross_block{
public:
	block cb1;
	block cb2;
	block cb3;
	block cb4;
	block cb5;

	cross_block(block cc1, block cc2, block cc3, block cc4, block cc5) {
		this->cb1 = block(cc1.get_xLocation(), cc1.get_yLocation(), cc1.get_color());
		this->cb2 = block(cc2.get_xLocation(), cc2.get_yLocation(), cc2.get_color());
		this->cb3 = block(cc3.get_xLocation(), cc3.get_yLocation(), cc3.get_color());
		this->cb4 = block(cc4.get_xLocation(), cc4.get_yLocation(), cc4.get_color());
		this->cb5 = block(cc5.get_xLocation(), cc5.get_yLocation(), cc5.get_color());
	}
	void go_down() {
		this->cb1.set_location(this->cb1.get_yLocation() + 1, this->cb1.get_xLocation());
		this->cb2.set_location(this->cb2.get_yLocation() + 1, this->cb2.get_xLocation());
		this->cb3.set_location(this->cb3.get_yLocation() + 1, this->cb3.get_xLocation());
		this->cb4.set_location(this->cb4.get_yLocation() + 1, this->cb4.get_xLocation());
		this->cb5.set_location(this->cb5.get_yLocation() + 1, this->cb5.get_xLocation());
	}
	void go_left() {
		this->cb1.set_location(this->cb1.get_yLocation(), this->cb1.get_xLocation() - 1);
		this->cb2.set_location(this->cb2.get_yLocation(), this->cb2.get_xLocation() - 1);
		this->cb3.set_location(this->cb3.get_yLocation(), this->cb3.get_xLocation() - 1);
		this->cb4.set_location(this->cb4.get_yLocation(), this->cb4.get_xLocation() - 1);
		this->cb5.set_location(this->cb5.get_yLocation(), this->cb5.get_xLocation() - 1);
	}
	void go_right() {
		this->cb1.set_location(this->cb1.get_yLocation(), this->cb1.get_xLocation() + 1);
		this->cb2.set_location(this->cb2.get_yLocation(), this->cb2.get_xLocation() + 1);
		this->cb3.set_location(this->cb3.get_yLocation(), this->cb3.get_xLocation() + 1);
		this->cb4.set_location(this->cb4.get_yLocation(), this->cb4.get_xLocation() + 1);
		this->cb5.set_location(this->cb5.get_yLocation(), this->cb5.get_xLocation() + 1);
	}
	bool can_down(int board[][5]) {
		if ((board[this->cb1.get_yLocation() + 1][this->cb1.get_xLocation()] != 0) ||
			(board[this->cb2.get_yLocation() + 1][this->cb2.get_xLocation()] != 0) ||
			(board[this->cb3.get_yLocation() + 1][this->cb3.get_xLocation()] != 0)
			) {
			return false;
		}
		else if (this->cb3.get_yLocation() >= 11) {
			return false;
		}
		else {
			return true;
		}
	}
	bool can_right(int board[][5]) {
		if ((board[this->cb2.get_yLocation()][this->cb2.get_xLocation()+1] != 0) ||
			(board[this->cb3.get_yLocation()][this->cb3.get_xLocation()+1] != 0) ||
			(board[this->cb4.get_yLocation()][this->cb4.get_xLocation()+1] != 0)
			) {
			return false;
		}
		else if (this->cb2.get_xLocation() >= 4) {
			return false;
		}
		return true;
	}
	bool can_left(int board[][5]) {
		if ((board[this->cb1.get_yLocation()][this->cb1.get_xLocation() - 1] != 0) ||
			(board[this->cb3.get_yLocation()][this->cb3.get_xLocation() - 1] != 0) ||
			(board[this->cb4.get_yLocation()][this->cb4.get_xLocation() - 1] != 0)
			) {
			return false;
		}
		else if (this->cb1.get_xLocation() <= 0) {
			return false;
		}
		return true;
	}
	int* get_Xs() {
		int xArray[5] = {this->cb1.get_xLocation(),this->cb2.get_xLocation(),this->cb3.get_xLocation(),this->cb4.get_xLocation(),this->cb5.get_xLocation()};
		return xArray;
	}
	int* get_Ys() {
		int yArray[5] = { this->cb1.get_yLocation(),this->cb2.get_yLocation(),this->cb3.get_yLocation(),this->cb4.get_yLocation(),this->cb5.get_yLocation() };
		return yArray;
	}
};
