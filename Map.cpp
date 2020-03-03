#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include "Map.h"
#include "constant.h"
#include "interaction.h"
#include "Interface.h"

int drawMap();

//��¼���ӵ���Ŀ
int cntFood;
int cntJudge;
//��¼Ѫ��
int cntBlood;


/*******************************
  *Description������ؿ���Ŀ��ƺ���
  *Last edited by: ϯʫ��
*********************************/
void inLevel()
{
    PIMAGE img = newimage();
    getimage(img, "img\\di.jpg",0,0);
    putimage(0, 0, img);
    
	drawMap();
	
    for ( ; is_run();delay_fps(10) )
    {
        //�����ƶ�
        roleMove();
        //�ж��Ƿ���ײ
        crashJudge();
        //��������ƶ�
        mstMove();
        
        //�ж��Ƿ�������ж��ӣ����������һ�ؿ�
        if(cntJudge==0)
        {
            //showScore();
            //������һ�ؿ�
            delay_ms(60);
            enterNext();
        }
        if(roleBlood==0)
        {
            //cleardevice();
            dieOver();
        }
        
    }

}


extern int WIDTH;
extern int LENGTH; 


/*******************************
  *Description�����ɵ�ͼ 
  *Last edited by: ϯʫ��
*********************************/
int drawMap()
{
	PIMAGE imgMap;
	int x =0;
    int y =0;
    
	//ÿ�����õ�ͼ�������ݹ���
    cntFood=0;
    cntBlood=0;
    
	showScore();
	
	for(int i=0;i<WIDTH;i++)
    {
        y=i*55;
        for(int j=0;j<LENGTH;j++)
        {
            x=j*50;
            imgMap=newimage();
            //����
            if(pMap[i][j]==0)
            {
                getimage(imgMap,"img\\food.jpg",0,0);
                putimage(x,y,imgMap);

                //������ʣ��������������������
                cntFood++;
            }

            //cntJudge=cntFood;
            //��
            else if(pMap[i][j]==1)
            {
                getimage(imgMap,"img\\shu.jpg",0,0);
                putimage(x,y,imgMap);

            }
            //ǽ
            else if(pMap[i][j]==2)
            {
                getimage(imgMap,"img\\wall.jpg",0,0);
                putimage(x,y,imgMap);

            }
            //����
            else if(pMap[i][j]==3)
            {
                getimage(imgMap,"img\\guaiwu1.jpg",0,0);
                putimage(x,y,imgMap);
                //�����������ڵ�λ��
                mstrow=i;
                mstcol=j;
                //��������ƶ����������ǣ�i,j��==(mstrow,mstcol)
                //ÿ�α�����ͨ����������pMap[mstrow][mstcol]��ֵ��ͼ�������꣨i,j������(mstrow,mstcol)
                //���Բ���Ҫ�޸�pMap[mstrow][mstcol]�ĺ�������
            }

            else if(pMap[i][j]==5)  //��
            {
                getimage(imgMap,"img\\renL.jpg",0,0);
                putimage(x,y,imgMap);
            }
            else if(pMap[i][j]==6)  //��
            {
                getimage(imgMap,"img\\renR.jpg",0,0);
              putimage(x,y,imgMap);
            }
            else if(pMap[i][j]==7) //��
            {
                getimage(imgMap,"img\\renU.jpg",0,0);
                putimage(x,y,imgMap);
            }
            else if(pMap[i][j]==8) //��
            {
                getimage(imgMap,"img\\renD.jpg",0,0);
                putimage(x,y,imgMap);
            }
            else if(pMap[i][j]==9)  //��
            {
                getimage(imgMap,"img\\white.jpg",0,0);
                putimage(x,y,imgMap);
            }
            //Ѫ��
            else if(pMap[i][j]==10)
            {
                getimage(imgMap,"img\\blood.jpg",0,0);
                putimage(x,y,imgMap);
                //������ʣ��Ѫ��
                cntBlood++;
            }

            //����
            else if(pMap[i][j]==4)
            {
                getimage(imgMap,"img\\ren.jpg",0,0);
                putimage(x,y,imgMap);
                row=i;
                col=j;

                /*pMap[i][j]==6;------->�ÿգ�����ͼ��ʵ�ָ��º�ԭλ�õ�ͼƬ��ʧ
                �������ɵ�ͼ
                    row=i;
                    col=j;
                    �� pMap[row][col-1] ����һ��λ����Ϊ pMap[row][col]==9 �������������ɵ�ͼ�ĺ���updMap
                                        ����λ����Ϊ pMap[row][col-1]==5
                    �� pMap[row][col+1]  ��Ϊ6
                    �� pMap[row-11][col]     7
                    �� pMap[row+1][col]      8
                */
            }
            delimage(imgMap);

        }

        //��������֮���ʣ�ඹ����Ŀ
        cntJudge=cntFood;
        //��������
        roleBlood=cntBlood;
        //������������
        score=(TOTAL-cntJudge)*5;
    }
    
    return 0;
}
