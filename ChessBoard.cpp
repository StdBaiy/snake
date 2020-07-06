#include<cmath>
#include "ChessBoard.h"
#include"snake.h"
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<cstdio>
#include <windows.h>
#include<string>
using namespace std;

void ChessBoard::newGame() {
	score = 0;
	system("cls");
	cout << "\n\n\t\tThe game is about to begin!" << endl;//开始界面
	long start = clock();
	while (clock() - start <= 1000);
	system("cls");
	cout << "\n\n\t\t\tReady?  " << endl;
	while (clock() - start <= 2000);
	system("cls");

	cout << "Score: " << score << endl << endl;//计分板
	cout << "MaxScore: "<<MaxScore << endl << endl;

	for (int i = 1; i <= HEIGHT - 2; i++)//打印地图
		for (int j = 1; j <= WIDTH - 2; j++)
			board[i][j] = ' ';
	for (int i = 0; i <= HEIGHT - 1; i++)
		board[0][i] = board[HEIGHT - 1][i] = '#';
	for (int i = 1; i <= HEIGHT - 2; i++)
		board[i][0] = board[i][WIDTH - 1] = '#';

	for (int i = 2; i != 6; ++i) {
		board[3][i] = '*';
	}

	for (int i = 0; i != WIDTH; ++i) {
		for (int j = 0; j != HEIGHT; ++j)
			cout << board[i][j] << ' ';
		cout << endl;
	}

	int i = 0,foodNum=3;
	while (i!=foodNum)//同时在场的食物有三个,每吃掉一个就刷新
		makeFood(i++,0);
}

ChessBoard::ChessBoard():MaxScore(0){}

void ChessBoard::makeFood(int i,int len)
{
	if (len + 3 < (WIDTH - 1) * (HEIGHT - 1)) {//判断棋盘已满的情况
		srand(time(0) + (time_t)(200 * i));
		int tmpX = 0, tmpY = 0;
		while (board[tmpX][tmpY] != ' ') {
			tmpX = abs(rand()) % (WIDTH - 2) + 1;
			tmpY = abs(rand()) % (HEIGHT - 2) + 1;
		}
		PrintChar("$ ", 2, tmpY * 2, tmpX + 4);
		foodX[i] = tmpX;//初始化坐标
		foodY[i] = tmpY;
	}
	else {
		foodX[i] = -1;
	}
}



