#include<stdio.h>
#include<iostream>
using namespace std;
#define length  3
#define wide    3


//函数声明
void initialization(char coordinate[length][wide],int a,int b);
void map(char coordinate[length][wide], int a, int b);
void player1(char coordinate[][wide], int a, int b);
void player2(char coordinate[][wide], int a, int b);
int win(char coordinate[][wide], int a, int b);

int main()
{
	//创建图，先创建数组，数组初始化
	char   coordinate[length][wide];//coordinate坐标
	//初始化-初始化函数
	initialization(coordinate,length,wide);//initialization初始化
	//地图函数
	map(coordinate, length, wide);
	int a = 0;
	int b = 0;
	int c = 1;
	for(;b<3;b++)
	{
		player1(coordinate, length, wide);
		a=win(coordinate, length, wide);
		if (a)
		{
			printf("玩家一获胜");
			c = 0;
			break;
		}
		player2(coordinate, length, wide);
		a=win(coordinate, length, wide);
		if (a)
		{
			printf("玩家二获胜");
			c = 0;
			break;
		}
	}
	if (c)
	{
		player1(coordinate, length, wide);
		a=win(coordinate, length, wide);
		if (a)
		{
			printf("玩家一获胜");
		}
		else
			printf("平局");
	}
	return 0;
}



void initialization(char coordinate[length][wide], int a, int b)
{
	for (a = a - 1;a >= 0;a--)
	{
		for (b = b - 1; b >= 0; b--)
		{
			coordinate[a][b] =' ';
		}
		b = wide;
	}
}


void map(char coordinate[length][wide], int a, int b)
{
	int x;
	for (x=0;x<b-1;x++)
	{	
		printf(" %c | %c | %c \n",coordinate[0][x], coordinate[1][x], coordinate[2][x]);
	    printf("---|---|---\n");
	}
	printf(" %c | %c | %c \n", coordinate[0][x], coordinate[1][x], coordinate[2][x]);
}


void player1(char coordinate[][wide], int a, int b)
{
	int x;
	int y;
	printf("玩家一移动请输入坐标");
	cin >> x >> y;
	x = x - 1;
	y = y - 1;
	//for (;;)
	//{
	//	if (coordinate[x][y] != ' ')
	//	{
	//		printf("位置占用请玩家一请重新输入坐标");
	//		cin >> x >> y;
	//		x = x - 1;
	//		y = y - 1;
	//		continue;
	//	}
	//	break;
	//}
	while (coordinate[x][y] != ' ')
	{
		printf("位置占用请玩家一请重新输入坐标");
		cin >> x >> y;
		x = x - 1;
		y = y - 1;
	}
	coordinate[x][y] = '#';
	map(coordinate, length, wide);
}
void player2(char coordinate[][wide], int a, int b)
{
	int x;
	int y;
	printf("玩家二移动请输入坐标");
	cin >> x >> y;
	x = x - 1;
	y = y - 1;
	//for (;;)
	//{
	//	if (coordinate[x][y] != ' ')
	//	{
	//		printf("位置占用请玩家二请重新输入坐标");
	//		cin >> x >> y;
	//		x = x - 1;
	//		y = y - 1;
	//		continue;
	//	}
	//	break;
	//}
	while(coordinate[x][y] != ' ')
	{
		printf("位置占用请玩家二请重新输入坐标");
		cin >> x >> y;
		x = x - 1;
		y = y - 1;
	}
	coordinate[x][y] = '*';
	map(coordinate, length, wide);
}
int win(char coordinate[][wide], int a, int b) 
{
	for (a=a-1; a >= 0; a--)
	{
		if (coordinate[a][0] == coordinate[a][1] && coordinate[a][0] == coordinate[a][2] && coordinate[a][0] != ' ')
		{
			return 1;
		}
	}
	for (b = b - 1; b >= 0; b--)
	{
		if (coordinate[0][b] == coordinate[1][b] && coordinate[0][b] == coordinate[2][b] && coordinate[0][b] != ' ')
		{
			return 1;
		}
	}
	if (coordinate[0][0] == coordinate[1][1] && coordinate[0][0] == coordinate[2][2] && coordinate[0][0] != ' ')
	{
		return 1;
	}
	if (coordinate[2][0] == coordinate[1][1] && coordinate[2][0] == coordinate[0][2] && coordinate[2][0] != ' ')
	{
		return 1;
	}
	return 0;
}
