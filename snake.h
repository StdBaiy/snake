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
	int length;//��������
	int headX,headY, tailX,tailY;//ͷ��β�͵�����
	int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//���ڵ������������
	vector<int> headDirect;//�����ߵ�ǰ�ƶ�����,
	void move(ChessBoard&cb);//�����ƶ��ĺ���
	int speed,MaxSpeed;//��λ:ms,ÿ����speedʱ��֮����ǰ��һ��
public:
	snake(ChessBoard&cb);
	void reload();
};

