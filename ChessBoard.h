#pragma once
#include"snake.h"
#define WIDTH 22
#define HEIGHT 22

extern void PrintChar(const char* ch, UINT count, UINT x, UINT y);

class ChessBoard
{		
	friend class snake;
public:
	void makeFood(int i, int len);//i�����������,len�����峤��
	ChessBoard();
private:
	void newGame();
	char board [WIDTH][HEIGHT];//����,���ڱ�����Ϸ��Ҫ��Ϣ	
	//���̵ı߽���#��ʾ,�����ߵĵط��ÿո��ʾ,�ߵ�������*��ʾ,ʳ����$��ʾ
	//�ߵ����в��������ڸı�board������
	int foodX[3], foodY[3];
	//EatenFood������������,��Ӧ���ϵ�����ʳ��;
	int score, MaxScore;
};

