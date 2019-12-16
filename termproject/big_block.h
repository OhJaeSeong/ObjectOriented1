#include <iostream>

using namespace std;
class big_block {
private:
	enum Shape {
		CROSS_BLOCK,
		FOLD_BLOCK,
		TREE_BLOCK
	};
public:
	virtual bool can_right(int board[][5]) = 0;
	virtual bool can_left(int board[][5]) = 0;
	virtual bool can_down(int board[][5]) = 0;
	virtual void go_down() = 0;
	virtual Shape shapes() const = 0;
}