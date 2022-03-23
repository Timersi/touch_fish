/*************************************************************************
	> File Name: /mnt/share/process.c
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2022年03月21日 星期一 14时19分58秒
 ************************************************************************/

#include<stdio.h>

typedef enum{
	first=1,
	second,
	third,
	fourth,
	fifth,
	sixth,
	seventh,
	eighth,
	nineth,
	tenth;
};

void moto_on(){

}

void led_on()
{

}

void relay_on(){
}

int main(void)
{
	int cnt_timer_add=0,water_on_add=0,moto_on_add=0;
	int moto_bit=0,relay_bit=0,led_bit=0;
	int temp,water,humi;
	int temp_set,water_set,humi_set;
	while(1)
	{
		if (temp >= temp_set)
		{
			switch(temp-temp_set)
			{
				case 1:
					water_on_add+=1;	
					break;
				case 2:
					water_on_add+=2;
					break;
				case 3:
					water_on_add+=3;
					break;
				case 4:
					water_on_add+=4;
					break;
				case 5:
					water_on_add+=5;
					break;
				case 6:
					water_on_add+=6;
					break;
				case 7:
					water_on_add+=7;
					break;
				case 8:
					water_on_add+=8;
					break;
				case 9:
					water_on_add+=9;
					break;
				case 10:
					water_on_add+=10;
					break;
		}
		else if(temp<temp_set)
		{
			switch(temp-temp_set)
			{
				case -1:
					cnt_timer_add+=1;
					break;
				case -2:
					cnt_timer_add+=2;
					break;
				case -3:
					cnt_timer_add+=3;
					break;
				case -4:
					cnt_timer_add+=4;
					break;
				case -5:
					cnt_timer_add+=5;
					break;
				case -6:
					cnt_timer_add+=6;
					break;
				case -7:
					cnt_timer_add+=7;
					break;
				case -8:
					cnt_timer_add+=8;
					break;
				case -9:
					cnt_timer_add+=9;
					break;
				case -10:
					cnt_timer_add+=10;
					break;
			}
		}
		if(water<=water_set)
		{
			switch((int)((water-water_set)/10))
			{
				case 10:
					water_on_add+=1;	
					break;
				case 9:
					water_on_add+=2;
					break;
				case 8:
					water_on_add+=3;
					break;
				case 7:
					water_on_add+=4;
					break;
				case 6:
					water_on_add+=5;
					break;
				case 5:
					water_on_add+=6;
					break;
				case 4:
					water_on_add+=7;
					break;
				case 3:
					water_on_add+=8;
					break;
				case 2:
					water_on_add+=9;
					break;
				case 1:
					water_on_add+=10;
					break;
				
			}
		}
		else if(water>water_set)
		{
			switch((int)((water-water_set)/10))
			{
				case -1:
					cnt_timer_add+=1;
					moto_on_add+=1;
					break;
				case -2:
					cnt_timer_add+=2;
					moto_on_add+=2;
					break;
				case -3:
					cnt_timer_add+=3;
					moto_on_add+=3;
					break;
				case -4:
					cnt_timer_add+=4;
					moto_on_add+=4;
					break;
				case -5:
					cnt_timer_add+=5;
					moto_on_add+=5;
					break;
				case -6:
					cnt_timer_add+=6;
					moto_on_add+=6;
					break;
				case -7:
					cnt_timer_add+=7;
					moto_on_add+=7;
					break;
				case -8:
					cnt_timer_add+=8;
					moto_on_add+=8;
					break;
				case -9:
					cnt_timer_add+=9;
					moto_on_add+=9;
					break;
				case -10:
					cnt_timer_add+=10;
					moto_on_add+=10;
					break;

			}
		}
/*****************************温度调整设置****************/		
		if(humi>=humi_set)
		{
			switch(humi-humi_set)
			{
				case -1:
					cnt_timer_add+=1;
					break;
				case -2:
					cnt_timer_add+=2;
					break;
				case -3:
					cnt_timer_add+=3;
					break;
				case -4:
					cnt_timer_add+=4;
					break;
				case -5:
					cnt_timer_add+=5;
					break;
				case -6:
					cnt_timer_add+=6;
					break;
				case -7:
					cnt_timer_add+=7;
					break;
				case -8:
					cnt_timer_add+=8;
					break;
				case -9:
					cnt_timer_add+=9;
					break;
				case -10:
					cnt_timer_add+=10;
					break;
			}
		}
		else if(temp<temp_set)
		{
			switch(temp-temp_set)
			{
				
			}
		}

/***********************开关操作处理**********************/				
		if(water_on_add==150)
		{
			relay_on();
			delay_ms(2000);
			~relay_on();
			water_on_add=0;
		}
		if(cnt_timer_add==3000)
		{
			//led_on();
			time_set_num+=0.5;
		}
		if(moto_on_add==100)
		{
			moto_on();

			moto_on_add=0;
		}

	}
}
