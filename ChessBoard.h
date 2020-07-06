#pragma once
#include <windows.h>
#include<cstdio>
#include"ChessBoard.h"
#include<vector>
using namespace std;

extern void PrintChar(const char* ch, UINT count, UINT x, UINT y);

class ChessBoard;

class snake
{
private:
	int length;
	int headX,headY, tailX,tailY;
	int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<int> headDirect;
	void move(ChessBoard&cb);
	int speed,MaxSpeed;
public:
	snake(ChessBoard&cb);
	void reload();
};

