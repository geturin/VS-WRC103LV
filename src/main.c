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
	while (1)
	{
	LED(3);
	while(getSW() != 1);	//ボタンが押されるまで待つ
	while(getSW() == 1);	//ボタンが離されるまで待つ

	toNEXT();
	toNEXT();
	toNEXT();
	move();
	turn_right();
	move();
	turn_right();
	toNEXT();
	toNEXT();
	toNEXT();
	move();
	turn_left();
	move();
	turn_left();
	toNEXT();
	toNEXT();
	toNEXT();
	move();
	turn_left();
	toNEXT();
	move();
	turn_left();
	move();
	turn_left();
	toNEXT();
	move();
	turn_right();
	move();
	turn_right();
	toNEXT();
	move();
	turn_left();
	move();
	turn_left();
	toNEXT();
	move();
	turn_right();
	move();
	turn_right();
	toNEXT();
	move();
	BuzzerStart();

	
	
	}
	

	
	


}



