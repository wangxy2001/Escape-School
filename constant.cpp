#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include "constant.h"


int WIDTH = 10;
int LENGTH = 10;

//��¼Ѫ��
int roleBlood=0;
//��¼����
int score=0;
//�жϹؿ�
int lvFlag=0;
int TOTAL=0;


int pMap[10][10]={0};

/*
0  ����
1  ǽ1 
2  ǽ2
4  ������
9  �հ� 
10 Ѫ��
*/ 
const int pMap1[10][10]=
{
1,1,1,1,1,1,1,1,1,1,
1,9,0,0,0,0,0,0,9,1,
1,4,9,2,9,9,2,9,9,1,
1,0,2,9,9,9,9,2,0,1,
1,9,9,9,3,9,9,9,9,1,
1,0,2,9,9,9,9,2,0,1,
1,0,9,2,9,9,2,9,0,1,
1,0,0,0,0,0,0,0,0,1,
1,9,1,1,9,9,1,1,9,1,
10,10,10,9,9,9,9,9,9,9
};

const int pMap2[10][10]=
{
1,1,1,1,1,1,1,1,1,1,
1,0,0,2,0,0,0,0,0,1,
1,0,9,2,9,9,9,2,2,1,
1,0,9,2,9,9,9,9,0,1,
1,0,9,9,3,9,9,9,0,1,
1,9,9,9,9,9,2,9,9,1,
1,2,2,9,4,9,2,9,9,1,
1,9,9,9,9,9,2,9,9,1,
1,1,1,1,1,1,1,1,1,1,
10,10,10,9,9,9,9,9,9,9
};

const int pMap3[10][10]=
{
1,1,1,1,1,1,1,1,1,1,
1,0,0,2,0,0,2,0,0,1,
1,0,2,9,9,9,9,2,0,1,
1,0,2,9,9,9,9,2,0,1,
1,9,9,9,3,9,9,9,9,1,
1,2,9,9,9,9,9,9,2,1,
1,4,9,2,9,9,2,9,9,1,
1,9,9,2,9,9,2,9,9,1,
1,1,1,1,1,1,1,1,1,1,
10,10,10,9,9,9,9,9,9,9
};