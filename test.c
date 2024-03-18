#define _CRT_SECURE_NO_WARNINGS
//����������

#include<stdio.h>
#include "game.h"
#include<windows.h>
#include<stdlib.h>

//��Ϸ����
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

//��Ϸ����
void game()
{
	char ret = 0;
	//��������������Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�ʤ��
		IsWin(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		
		//��������
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
		printf("Ӯ�����ϻ�����\n");
	}
	else if (ret == '#')
	{
		printf("�㻹�������ϻ���\n");
	}
	else if (ret == 'Q')
	{
		printf("�;֣�������������\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printf("\n");
		printf("��Ϸ��׼�����أ���Ҫ��Ŷ\n");
		Sleep(2000);
		system("cls");
		menu();
		printf("������:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������\n");
			break;
		}
	} while(input);
}
int main()
{
	test();
	return 0;
}