#pragma once
#include<graphics.h>
#define N 20
class Game
{
public:
	Game(void);
	~Game(void);
	void initGame();
	void playChess();
	int judge(int, int);
protected:
	int flag;
	HWND hWnd;
};

