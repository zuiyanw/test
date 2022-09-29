game.c 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
//函数实现
void Initboard(char board[ROW][COL], int row, int col)//数组初始化函数
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//row 行
	{
		for (j = 0; j < col; j++) //col 列
		{
			board[i][j] = ' ';//已经初始化好了
		}
	}

}
void Display(char board[ROW][COL], int row, int col)//棋盘打印函数
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//row 行 意思需要打印几行
	{
		for (j = 0; j < col; j++)//col=3 依次打印 board[0][1]  [0][2] [0][3]
		{
			printf(" %c ", board[i][j]);//col:列 第一行：“ 空格 | 空格 | 空格 ”
			if (j < col - 1)
			{
				printf("|");
			}
		}//第一行打印完毕 换行打印 ---|---|---
		printf("\n");
		for (j = 0; j < col; j++)//开始打印---|---|---
		{
			if (i < row - 1)//如果在最后一行不再打印---|---|--- 设置一个条件 跟row有关
			{               //row 行
				printf("---");
				if (j < col - 1)//最后面没有| 设置条件 与col(列)有关
				{
					printf("|");
				}
			}
		}
		printf("\n");//第二行的---|---|--- 打印完成 换行打印下一行数组(已经初始化成了空格)
	}
}
void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d%d", &x, &y);
		if ((x > 0 && x<= row) && (y>0 && y <= row))
		{

			if (board[x - 1][y - 1] == ' ')//玩家理解：    [1][1]  [1][2]  [1][3]
			{                              //             [2][1]  [2][2]  [2][3]
				//             [3][1]  [3][2]  [3][3]
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该格子已被占，请重新输入：\n");
		}
		else
			printf("坐标非法, 输入错误\n");
	}
}
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
while (1)
{
	x = rand() % row;//一个整数对n取模的结果范围为： 0 到n− 1,电脑输的话 坐标还从00-02 00-20结束
	y = rand() % col;
	if (board[x][y] == ' ')
	{
		board[x][y] = '#';
		break;
	}
}
}
int is_full(char board[ROW][COL], int row, int col)
//判断整个棋盘所有的棋位 是否被占据
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//行
	{
		for (j = 0; j < col; j++)//列
		{
                    
if (board[i][j] == ' ')
		    {
			return 0;                        
		    }
                    else
                    a++;
		}
	}
        if(a==9)
	{return 1;}

}
char is_win(char board[ROW][COL], int row, int col)//判断胜利函数
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//判断第一行
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
                         
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
                        printf("此棋子为board[1][i]");       
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];                      
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}//以上循环都不经过的话 说明有2种情况：1.格子满了 平局 2.格子没满，需要继续下棋子
	if (is_full(board, row, col) == 1)//创建一个判断棋盘是否落满的函数 1表示棋盘满了 
	{
 	return 'p';	
	else
		return 'c';

	}
	}
