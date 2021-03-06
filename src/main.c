/*インクルード***********************************************************/
#include "lpc13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

/*マクロ***********************************************************/

/*グローバル変数***********************************************************/

/*メイン関数***********************************************************/
void main(void)
{
	//制御周期の設定[単位：Hz　範囲：30.0~]
	const unsigned short MainCycle = 60;
	Init(MainCycle);		//CPUの初期設定
	int type;
	int counter=0;
	while (1)
	{
	LED(3);
	while(getSW() != 1);	//ボタンが押されるまで待つ
	while(getSW() == 1);	//ボタンが離されるまで待つ
	LED(0);
	type=0;
	BuzzerStart();

	while (counter<=20)
	{
		if (getSW()==1)
		{
			type +=1;
			if (type>3)
			{
				type=0;
			}
			while(getSW() == 1);
			counter=0;						
		}

		LED(type);
		counter+=1;
		Wait(100);		
	}
	counter=0;
	BuzzerStop();
	while(getSW() != 1);	//ボタンが押されるまで待つ
	while(getSW() == 1);
	if (type==0)
	{
		easy_road();
	}
	else{
		hard_road(type-1);
	}
	



	


	}
	
	

	






	
}



