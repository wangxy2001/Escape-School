#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

#include "constant.h"
#include "interaction.h"
#include "Interface.h"
#include "Map.h"
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
