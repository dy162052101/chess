#include "Game.h"
#include<math.h>
int chessboard[N][N]={0};
Game::Game(void)
{
	flag=0;
}
Game::~Game(void)
{
}
void Game::initGame()
{
	initgraph(600, 500);
	loadimage(NULL, L"1.jpg");

	for (int i = 1; i < 20; i++)
	{
		setlinestyle(PS_SOLID, 3);
		setlinecolor(BLACK);
		line(i * 25, 0, i * 25, 500);
		line(0, i * 25, 500, i * 25);
	}
	setlinestyle(PS_SOLID, 3);
	line(500, 0, 500, 500);
	line(0, 500, 500, 500);
	
	outtextxy(505, 20, L"黑棋：玩家1");
	outtextxy(505, 50, L"白棋：玩家2");
}



void Game::playChess()
{
	int i, j;
	int a=0, b=0;
	int x, y;
	MOUSEMSG m;
	hWnd = GetHWnd();
	while (1)
	{
		m = GetMouseMsg();
		for (i = 1; i < 20; i++)
		{
			for (j = 1; j < 20; j++)
			{
				if (abs(i * 25 - m.x) < 12.5&&abs(j * 25 - m.y) < 12.5)
				{
					x = i * 25;
					y = j * 25;
					a = i;
					b = j;
				}
			}

		}
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (flag% 2 == 1)
			{
				outtextxy(505, 200, L"请白棋落子");
				if (chessboard[a][b] != 0)
				{
					MessageBox(hWnd, L"请重新选择落子的地点", L"这里已经落子", MB_OK);
					continue;
				}
				else
				{
					setfillcolor(WHITE);
					solidcircle(x, y, 10);
					chessboard[a][b] = 2;
				}
			
			}
			else
			{
				outtextxy(505, 200, L"请黑棋落子");
				if (chessboard[a][b] != 0)
				{
					MessageBox(hWnd, L"请重新选择落子的地点", L"这里已经落子", MB_OK);
					continue;
				}
				else
				{
					setfillcolor(BLACK);
					solidcircle(x, y, 10);
					chessboard[a][b] = 1;
				}

			}
			flag++;
		}
		
		if (judge(a, b))
		{
			if (1 == flag% 2)
			{
				MessageBox(hWnd, L"黑棋胜利", L"游戏结束", MB_OK);
				exit(0);	
			}
			else
			{
				MessageBox(hWnd, L"白棋胜利", L"游戏结束", MB_OK);
				exit(0);	
			}
		}
	}
	
}

int Game::judge(int x, int y)
{
	int i, j;
	int t = 2 - flag% 2;
	for (i = x - 4, j = y; i <= x; i++)
	{
		if (i >= 1 && i <= N - 4 && t == chessboard[i][j] && t == chessboard[i + 1][j] && t == chessboard[i + 2][j] && t == chessboard[i + 3][j] && t == chessboard[i + 4][j])
			return 1;
	}
	for (i = x, j = y - 4; j <= y; j++)
	{
		if (j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i][j + 1] && t == chessboard[i][j + 1] && t == chessboard[i][j + 3] && t == chessboard[i][j + 4])
			return 1;
	}
	for (i = x - 4, j = y - 4; i <= x, j <= y; i++, j++)
	{
		if (i >= 1 && i <= N - 4 && j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i + 1][j + 1] && t == chessboard[i + 2][j + 2] && t == chessboard[i + 3][j + 3] && t == chessboard[i + 4][j + 4])
			return 1;
	}
	for (i = x + 4, j = y - 4; i >= 1, j <= y; i--, j++)
	{
		if (i >= 1 && i <= N - 4 && j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i - 1][j + 1] && t == chessboard[i - 2][j + 2] && t == chessboard[i - 3][j + 3] && t == chessboard[i - 4][j + 4])
			return 1;
	}
	return 0;
}