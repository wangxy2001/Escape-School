#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

#include "Map.h"
#include "Interface.h"
#include "constant.h" 
#include "interaction.h"






//��¼����������������
//(row,col)
int row=0;
int col=0;
//��¼��������
//(mstrow,mstcol)
int mstrow=0;
int mstcol=0;





int main()
{
	//initialize game
    initgraph(550, 550);
    loadMenu();
    delay_ms(800); 
    homeMenu();
    
    //
    
    
    //end game 
    cleardevice();
    closegraph();
    return 0;
}

