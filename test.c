#define _CRT_SECURE_NO_WARNINGS
//测试三子棋

#include<stdio.h>
#include "game.h"
#include<windows.h>
#include<stdlib.h>

//游戏界面
void menu()
{
	printf("**********************************\n");
	printf("*****1. play         0. exit *****\n");
	printf("**********************************\n");
}

//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |   

//游戏本身
void game()
{
	char ret = 0;
	//用数组存放棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//游玩
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断胜负
		IsWin(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("赢了智障机了呢\n");
	}
	else if (ret == '#')
	{
		printf("你还不如智障机？\n");
	}
	else if (ret == 'Q')
	{
		printf("和局？！你在摸鱼吗\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printf("\n");
		printf("游戏在准备中呢，不要急哦\n");
		Sleep(2000);
		system("cls");
		menu();
		printf("请输入:>\n");
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
			printf("输入错误，请重试\n");
			break;
		}
	} while(input);
}
int main()
{
	test();
	return 0;
}