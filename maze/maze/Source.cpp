#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

FILE *f;
char maze[100][100];

int xStart, yStart;
int xEnd, yEnd;

struct player
{
	int x = 0, y = 0;
	bool end = false;
};

player hero;

int* ptrx = &hero.x;
int* ptry = &hero.y;

void createMaze()
{
	char temp = '0';
	f = fopen("maze.txt", "r");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fscanf(f, "%c", &temp);
			maze[i][j] = temp;
		}
	}
	fscanf(f, "%d", &xStart);
	fscanf(f, "%d", &yStart);
	fscanf(f, "%d", &xEnd);
	fscanf(f, "%d", &yEnd);
	hero.x = xEnd;
	hero.y = yEnd;
	fclose(f);
}

void outputMaze()
{
	maze[hero.x][hero.y] = 'H';
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << maze[i][j];
		}
		cout << endl;
	}
}

void moving(int* x, int* y)
{
	char moveKey = '0';
	while (true)
	{
		outputMaze();
		cin >> moveKey;
		/*putchar(moveKey);*/
		switch (moveKey)
		{
		case 'w':
		{
					system("cls");
					if ((*y - 1) >= 0 && maze[*x][(*y - 1)] == '0')
					{
						*y--;
					}
					outputMaze();
		}
			break;
		case 's':
		{
					system("cls");
					if ((*y + 1) < 4 && maze[*x][(*y - 1)] == '0')
					{
						*y++;
					}
					cout << maze[*x][(*y - 1)];
					outputMaze();
		}
			break;
		case 'a':
		{
					system("cls");
					if ((*x - 1) >= 0 && maze[(*x - 1)][*y] == '0')
					{
						*x--;
					}
					outputMaze();
		}
			break;
		case 'd':
		{
					system("cls");
					if ((*x + 1) < 4 && maze[(*x - 1)][*y] == '0')
					{
						*x++;
					}
					outputMaze();
		}
			break;
		default:
			break;
		}
	}
}

int main()
{
	createMaze();
	moving(ptrx, ptry);
}
