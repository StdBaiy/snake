#include<iostream>
#include<string>
#include"ChessBoard.h"
#include "snake.h"
#include<conio.h>
#include<ctime>
using namespace std;
void PrintChar(const char* ch, UINT count, UINT x, UINT y) //ch是要打印的字符,count是长度,x,y是控制台坐标
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	ULONG unuse;
	pos.X = x;
	pos.Y = y;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(h, &bInfo);
	WriteConsoleOutputCharacterA(h, ch, count, pos, &unuse);
}

void snake::move(ChessBoard&cb)
{
	MaxSpeed = 120;
	cb.newGame();
	int head = 0,tail=head-3;
	while (true) {
		headDirect.push_back(head==0?3:headDirect[head-1]);
		long start = clock();
		int tmpDirect = 0;
		while ((clock() - start <= speed)) {
			if (_kbhit()) {
				tmpDirect = _getch();
			}
		}
		//cout <<"tmpDirec: "<< tmpDirect << endl;
		if(head!=0)
		switch (tmpDirect) {//防止180°转弯
		case 72:
			if (headDirect[head-1] != 1)headDirect[head] = 0;
			break;//up
		case 80:
			if (headDirect[head-1] != 0)headDirect[head] = 1;
			break;//down
		case 75:
			if (headDirect[head-1] != 3)headDirect[head] = 2;
			break;//left
		case 77:
			if (headDirect[head-1] != 2)headDirect[head] = 3;
			break;//right
		default:
			break;
		}		
		headX+=direction[headDirect[head]][0];
		headY+=direction[headDirect[head]][1];
		if (cb.board[headX][headY]!='#'&&
			cb.board[headX][headY] != '*') {						
			cb.board[headX][headY] = '*';
			PrintChar("* ", 2, headY * 2, headX + 4);
			bool flagT = false,flagH=false;
			int tmpFood;
			for (int j = 0; j != 3; ++j) {
				if (cb.foodX[j] == headX && cb.foodY[j] == headY) {
					flagH = true;
				}
				if (cb.foodX[j] == tailX && cb.foodY[j] == tailY) {
					flagT = true;
					tmpFood = j;
				}
			}			

			if (flagH) {
				PrintChar("   ", 3, 7, 0);
				PrintChar(to_string(++cb.score).c_str(), to_string(cb.score).size(), 7, 0);
				if (speed - 10 >= MaxSpeed)speed -= 10;
			}
			
			if (flagT) {
				cb.makeFood(tmpFood, length++);
				++head;
				continue;
			}
			else {
				cb.board[tailX][tailY] = ' ';
				PrintChar("  ", 2, tailY * 2, tailX + 4);
				tailX += direction[(tail < 0) ? 3 : headDirect[tail]][0];
				tailY += direction[(tail < 0) ? 3 : headDirect[tail]][1];
				++tail;
			}
			++head;
		}
		else {
			PrintChar("GAME OVER", 11, 16, 13);
			PrintChar("                  ", 18, 12, 14);
			PrintChar("PLAY AGAIN? Y OR N", 18, 12, 15);
			char c;
			cin >> c;
			c = toupper(c);
			while (c !='Y'&&c!='N') {
				cin >> c;
				c = toupper(c);
			}
			if (c == 'Y') {
				cb.MaxScore = max(cb.MaxScore, cb.score);
				reload();
				move(cb);
			}
			return;
		}
	}
}

snake::snake(ChessBoard&cb)
{
	headX=3;
	headY=5;
	tailX=3;
	tailY=2;
	length=4;	
	speed = 250;
	move(cb);
}

void snake::reload()
{
	headX = 3;
	headY = 5;
	tailX = 3;
	tailY = 2;
	length = 4;
	speed = 250;
	headDirect.clear();
}


