//测试三字棋游戏
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
void menu()
{
	printf("*********************\n");
	printf("**1.play    0.exit***\n");
	printf("*********************\n");
}
//游戏的整个算法实现
void game()
{
	//数组-存放走出的棋盘信息
	char board[ROW][COL] = { 0 };//希望这个数组全部都是空格
	Initboard(board, ROW, COL);//使用函数 对数组进行初始化
	Display(board, ROW, COL);//用这个函数 需要在game.h头文件中声明 棋盘打印函数
	printf("请输入棋子的坐标>：\n");
	char ret = 0;
	while (1)//下棋：你一步 我一步 你一步 我一步，先放到一个while循环中 知道直到有人胜利
	{
		//玩家下棋（需要把棋子放在数组中 则需要把数组传过去，坐标也需要传过去）
		printf("玩家走：\n");
		playermove(board, ROW, COL);
		Display(board, ROW, COL);
		is_win(board, ROW, COL);//判断是否胜利函数
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;//c表示棋盘没满 需要继续下子 当ret='p'的时候 说明棋盘已满 需要跳出循环 所以break
		}
		else
		{
			if (ret == '*')
			{
				break;
			}
			else if (ret == '#')
			{
				break;
			}
			else if (ret == 'P')
			{
				break;
			}
		}
		//电脑下棋
		printf("电脑走：\n");
		computermove(board, ROW, COL);
		Display(board, ROW, COL);
		is_win(board, ROW, COL);//判断是否胜利函数
		if (ret != 'C')
		{
			break;//c表示棋盘没满 需要继续下子 当ret='p'的时候 说明棋盘已满 需要跳出循环 所以break
		}
		else	
		{
			if (ret == '*')
			{
				break;
			}
			else if (ret == '#')
			{
				break;
			}
			else if (ret == 'P')
			{
				break;
			}
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'P')
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入:\n");
			break;

		}
	} while (input);
}
int main()
{
	srand((unsigned int )time(NULL));//建立播种器,电脑输入坐标的时候用
	test();//建立测试函数
	return 0;
}
