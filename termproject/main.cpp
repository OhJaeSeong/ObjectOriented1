#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include "conio.h"
#include "block.h"
#include "big_block.h"
#include "fold_block.h"
#include "cross_block.h"
#include "tree_block.h"
; 
void draw_array(int board[][5]) {
	printf("%c[1;37m", 27);
	for (int k = 0; k < 12; k++) {
		for (int p = 0; p < 5; p++) {
			if (board[k][p] == 1) {
				printf("%c[1;31m", 27);
				std::cout << board[k][p];
				printf("%c[1;37m", 27);
			}
			else if (board[k][p] == 2) {
				printf("%c[1;32m", 27);
				std::cout << board[k][p];
				printf("%c[1;37m", 27);
			}
			else if (board[k][p] == 3) {
				printf("%c[1;34m", 27);
				std::cout << board[k][p];
				printf("%c[1;37m", 27);
			}
			else {
				std::cout << board[k][p];
			}
		}
		std::cout << "" << std::endl;
	}
}
int main() {
	//wcout.imbue(locale("kor"));
	//wcin.imbue(locale("kor"));
	int count = 0;
	int board[12][5];
	for (int x = 0; x < 12; x++) {
		for (int y = 0; y < 5; y++) {
			board[x][y] = 0;
		}
	}
	while (count < 20) {
		count++;
		srand((unsigned int)time(0));
		int shapeNumber = rand() % 3;
		if (shapeNumber == 0) { //cross
			int startPoint = rand() % 3 + 1; int y = 0;
			int cb1c = rand() % 3 + 1; int cb2c = rand() % 3 + 1; int cb3c = rand() % 3 + 1;
			int cb4c = rand() % 3 + 1; int cb5c = rand() % 3 + 1;
			block cb1(startPoint - 1, y, cb1c);
			block cb2(startPoint+1,y,cb2c);
			block cb3(startPoint, y+1 ,cb3c);
			block cb4(startPoint, y-1 ,cb4c);
			block cb5(startPoint ,y, cb5c);
			cross_block blk(cb1, cb2, cb3, cb4, cb5);
			board[blk.cb1.get_yLocation()][blk.cb1.get_xLocation()] = blk.cb1.get_color();
			board[blk.cb2.get_yLocation()][blk.cb2.get_xLocation()] = blk.cb2.get_color();
			board[blk.cb3.get_yLocation()][blk.cb3.get_xLocation()] = blk.cb3.get_color();
			board[blk.cb4.get_yLocation()][blk.cb4.get_xLocation()] = blk.cb4.get_color();
			board[blk.cb5.get_yLocation()][blk.cb5.get_xLocation()] = blk.cb5.get_color();
			int prev1x = blk.cb1.get_xLocation(); int prev1y = blk.cb1.get_yLocation();
			int prev2x = blk.cb2.get_xLocation(); int prev2y = blk.cb2.get_yLocation();
			int prev3x = blk.cb3.get_xLocation(); int prev3y = blk.cb3.get_yLocation();
			int prev4x = blk.cb4.get_xLocation(); int prev4y = blk.cb4.get_yLocation();
			int prev5x = blk.cb5.get_xLocation(); int prev5y = blk.cb5.get_yLocation();
			system("clear");
			draw_array(board);
			while (blk.can_down(board)) {
				clock_t start = clock();
				clock_t end = clock();
				while (end - start < 700) {
					if (_kbhit()) {
						int typing = _getch(); // 눌린 값 대입
						if (typing == 'q') {
							break;
						}
						else if (typing == 'a') {
							if (blk.can_left(board)) {
								blk.go_left();
							}
						}
						else if (typing == 's') {
							if (blk.can_down(board)) {
								blk.go_down();
							}
						}
						else if (typing == 'd') {
							if (blk.can_right(board)) {
								blk.go_right();
							}
						}
						board[prev1y][prev1x] = 0; board[prev2y][prev2x] = 0; board[prev3y][prev3x] = 0;
						board[prev4y][prev4x] = 0; board[prev5y][prev5x] = 0;
						board[blk.cb1.get_yLocation()][blk.cb1.get_xLocation()] = blk.cb1.get_color();
						board[blk.cb2.get_yLocation()][blk.cb2.get_xLocation()] = blk.cb2.get_color();
						board[blk.cb3.get_yLocation()][blk.cb3.get_xLocation()] = blk.cb3.get_color();
						board[blk.cb4.get_yLocation()][blk.cb4.get_xLocation()] = blk.cb4.get_color();
						board[blk.cb5.get_yLocation()][blk.cb5.get_xLocation()] = blk.cb5.get_color();
						prev1x = blk.cb1.get_xLocation(); prev1y = blk.cb1.get_yLocation();
						prev2x = blk.cb2.get_xLocation(); prev2y = blk.cb2.get_yLocation();
						prev3x = blk.cb3.get_xLocation(); prev3y = blk.cb3.get_yLocation();
						prev4x = blk.cb4.get_xLocation(); prev4y = blk.cb4.get_yLocation();
						prev5x = blk.cb5.get_xLocation(); prev5y = blk.cb5.get_yLocation();
						system("clear");
						draw_array(board);
					}
					end = clock();
				}
				system("clear");
				if (blk.can_down(board)) {
					blk.go_down();
				}
				board[prev1y][prev1x] = 0; board[prev2y][prev2x] = 0; board[prev3y][prev3x] = 0;
				board[prev4y][prev4x] = 0; board[prev5y][prev5x] = 0;
				board[blk.cb1.get_yLocation()][blk.cb1.get_xLocation()] = blk.cb1.get_color();
				board[blk.cb2.get_yLocation()][blk.cb2.get_xLocation()] = blk.cb2.get_color();
				board[blk.cb3.get_yLocation()][blk.cb3.get_xLocation()] = blk.cb3.get_color();
				board[blk.cb4.get_yLocation()][blk.cb4.get_xLocation()] = blk.cb4.get_color();
				board[blk.cb5.get_yLocation()][blk.cb5.get_xLocation()] = blk.cb5.get_color();
				prev1x = blk.cb1.get_xLocation(); prev1y = blk.cb1.get_yLocation();
				prev2x = blk.cb2.get_xLocation(); prev2y = blk.cb2.get_yLocation();
				prev3x = blk.cb3.get_xLocation(); prev3y = blk.cb3.get_yLocation();
				prev4x = blk.cb4.get_xLocation(); prev4y = blk.cb4.get_yLocation();
				prev5x = blk.cb5.get_xLocation(); prev5y = blk.cb5.get_yLocation();
				draw_array(board);
			}
		}
		else if (shapeNumber == 1) { //fold
			int startPoint = rand() % 3 + 1; int y = 0;
			int fb1c = rand() % 3+ 1; int fb2c = rand() % 3 + 1; int fb3c = rand() % 3 + 1;
			block fb1(startPoint-1,y,fb1c);
			block fb2(startPoint,y,fb2c);
			block fb3(startPoint,y-1,fb3c);
			fold_block blk(fb1,fb2,fb3);
			board[blk.fb1.get_yLocation()][blk.fb1.get_xLocation()] = blk.fb1.get_color();
			board[blk.fb2.get_yLocation()][blk.fb2.get_xLocation()] = blk.fb2.get_color();
			board[blk.fb3.get_yLocation()][blk.fb3.get_xLocation()] = blk.fb3.get_color();
			int prev1x = blk.fb1.get_xLocation(); int prev1y = blk.fb1.get_yLocation();
			int prev2x = blk.fb2.get_xLocation(); int prev2y = blk.fb2.get_yLocation();
			int prev3x = blk.fb3.get_xLocation(); int prev3y = blk.fb3.get_yLocation();
			system("clear");
			draw_array(board);
			while (blk.can_down(board)) {
				clock_t start = clock();
				clock_t end = clock();
				while (end - start < 700) {
					if (_kbhit()) {
						int typing = _getch(); // 눌린 값 대입
						if (typing == 'q') {
							break;
						}
						else if (typing == 'a') {
							if (blk.can_left(board)) {
								blk.go_left();
							}
						}
						else if (typing == 's') {
							if (blk.can_down(board)) {
								blk.go_down();
							}
						}
						else if (typing == 'd') {
							if (blk.can_right(board)) {
								blk.go_right();	
							}
						}
						board[prev1y][prev1x] = 0; board[prev2y][prev2x] = 0; board[prev3y][prev3x] = 0;
						board[blk.fb1.get_yLocation()][blk.fb1.get_xLocation()] = blk.fb1.get_color();
						board[blk.fb2.get_yLocation()][blk.fb2.get_xLocation()] = blk.fb2.get_color();
						board[blk.fb3.get_yLocation()][blk.fb3.get_xLocation()] = blk.fb3.get_color();
						prev1x = blk.fb1.get_xLocation(); prev1y = blk.fb1.get_yLocation();
						prev2x = blk.fb2.get_xLocation(); prev2y = blk.fb2.get_yLocation();
						prev3x = blk.fb3.get_xLocation(); prev3y = blk.fb3.get_yLocation();
						system("clear");
						draw_array(board);
					}
					end = clock();
				}
				system("clear");
				if (blk.can_down(board)) {
					blk.go_down();
				}
				board[prev1y][prev1x] = 0; board[prev2y][prev2x] = 0; board[prev3y][prev3x] = 0;
				board[blk.fb1.get_yLocation()][blk.fb1.get_xLocation()] = blk.fb1.get_color();
				board[blk.fb2.get_yLocation()][blk.fb2.get_xLocation()] = blk.fb2.get_color();
				board[blk.fb3.get_yLocation()][blk.fb3.get_xLocation()] = blk.fb3.get_color();
				prev1x = blk.fb1.get_xLocation(); prev1y = blk.fb1.get_yLocation();
				prev2x = blk.fb2.get_xLocation(); prev2y = blk.fb2.get_yLocation();
				prev3x = blk.fb3.get_xLocation(); prev3y = blk.fb3.get_yLocation();
				draw_array(board);
			}
		}
		else { //tree
			int startPoint = rand() % 5; int y = -1;
			int tb1c = rand() % 3 + 1; int tb2c = rand() % 3 + 1; int tb3c = rand() % 3 + 1;
			block tb1(startPoint,y, tb1c);
			block tb2(startPoint,y+1, tb2c);
			block tb3(startPoint,y+2, tb3c);
			tree_block blk(tb1,tb2,tb3);
			board[blk.tb1.get_yLocation()][blk.tb1.get_xLocation()] = blk.tb1.get_color();
			board[blk.tb2.get_yLocation()][blk.tb2.get_xLocation()] = blk.tb2.get_color();
			board[blk.tb3.get_yLocation()][blk.tb3.get_xLocation()] = blk.tb3.get_color();
			int prev1x = blk.tb1.get_xLocation(); int prev1y = blk.tb1.get_yLocation();
			int prev2x = blk.tb2.get_xLocation(); int prev2y = blk.tb2.get_yLocation();
			int prev3x = blk.tb3.get_xLocation(); int prev3y = blk.tb3.get_yLocation();
			system("clear");
			draw_array(board);
			while (blk.can_down(board)) {
				clock_t start = clock();
				clock_t end = clock();
				while (end - start < 700) {
					if (_kbhit()) {
						int typing = _getch(); // 눌린 값 대입
						if (typing == 'q') {
							break;
						}
						else if (typing == 'a') {
							if (blk.can_left(board)) {
								blk.go_left();
							}
						}
						else if (typing == 's') {
							if (blk.can_down(board)) {
								blk.go_down();
							}
						}
						else if (typing == 'd') {
							if (blk.can_right(board)) {
								blk.go_right();
							}
						}
						board[prev1y][prev1x] = 0; board[prev2y][prev2x] = 0; board[prev3y][prev3x] = 0;
						board[blk.tb1.get_yLocation()][blk.tb1.get_xLocation()] = blk.tb1.get_color();
						board[blk.tb2.get_yLocation()][blk.tb2.get_xLocation()] = blk.tb2.get_color();
						board[blk.tb3.get_yLocation()][blk.tb3.get_xLocation()] = blk.tb3.get_color();
						prev1x = blk.tb1.get_xLocation(); prev1y = blk.tb1.get_yLocation();
						prev2x = blk.tb2.get_xLocation(); prev2y = blk.tb2.get_yLocation();
						prev3x = blk.tb3.get_xLocation(); prev3y = blk.tb3.get_yLocation();
						system("clear");
						draw_array(board);
					}
					end = clock();
				}
				system("clear");
				if (blk.can_down(board)) {
					blk.go_down();
				}
				board[prev1y][prev1x] = 0; board[prev2y][prev2x] = 0; board[prev3y][prev3x] = 0;
				board[blk.tb1.get_yLocation()][blk.tb1.get_xLocation()] = blk.tb1.get_color();
				board[blk.tb2.get_yLocation()][blk.tb2.get_xLocation()] = blk.tb2.get_color();
				board[blk.tb3.get_yLocation()][blk.tb3.get_xLocation()] = blk.tb3.get_color();
				prev1x = blk.tb1.get_xLocation(); prev1y = blk.tb1.get_yLocation();
				prev2x = blk.tb2.get_xLocation(); prev2y = blk.tb2.get_yLocation();
				prev3x = blk.tb3.get_xLocation(); prev3y = blk.tb3.get_yLocation();
				draw_array(board);
			}
		}
	//	combo(board);
	}
}
