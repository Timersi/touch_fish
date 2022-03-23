/*************************************************************************
	> File Name: /mnt/share/process.c
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2022年03月21日 星期一 14时19分58秒
 ************************************************************************/

#include<stdio.h>

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
			if((temp-temp_set)>3)
			switch(temp-temp_set)
			{
				case 4:
					water_on_add+=1;
					break;
				case 5:
					water_on_add+=2;
					break;
				case 6:
					water_on_add+=3;
					break;
				case 7:
					water_on_add+=4;
					break;
				case 8:
					water_on_add+=5;
					break;
				case 9:
					water_on_add+=6;
					break;
				case 10:
					water_on_add+=7;
					break;
		}
		else if(temp<temp_set)
		{
			if((temp_set-temp)>3)
			switch(temp-temp_set)
			{
				case -4:
					cnt_timer_add+=1;
					break;
				case -5:
					cnt_timer_add+=2;
					break;
				case -6:
					cnt_timer_add+=3;
					break;
				case -7:
					cnt_timer_add+=4;
					break;
				case -8:
					cnt_timer_add+=5;
					break;
				case -9:
					cnt_timer_add+=6;
					break;
				case -10:
					cnt_timer_add+=7;
					break;
			}
		}
		if(water<=water_set)
		{
			if(((int)(water_set-water))>30)
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
				
			}
		}
		else if(water>water_set)
		{
			if(((int)(water-water_set))>30)
			switch((int)((water-water_set)/10))
			{
				case -4:
					cnt_timer_add+=1;
					moto_on_add+=1;
					break;
				case -5:
					cnt_timer_add+=2;
					moto_on_add+=2;
					break;
				case -6:
					cnt_timer_add+=3;
					moto_on_add+=3;
					break;
				case -7:
					cnt_timer_add+=4;
					moto_on_add+=4;
					break;
				case -8:
					cnt_timer_add+=5;
					moto_on_add+=5;
					break;
				case -9:
					cnt_timer_add+=6;
					moto_on_add+=6;
					break;
				case -10:
					cnt_timer_add+=7;
					moto_on_add+=7;
					break;

			}
		}

/*****************************温度调整设置****************/		
		if(humi>=humi_set)
		{
			if((humi-humi_set)>5)
			switch(humi_set-humi)
			{
				case -6:
					cnt_timer_add+=1;
					break;
				case -7:
					cnt_timer_add+=2;
					break;
				case -8:
					cnt_timer_add+=3;
					break;
				case -9:
					cnt_timer_add+=4;
					break;
				case -10:
					cnt_timer_add+=5;
					break;
			}
		}
		else if(humi<humi_set)
		{
			if((humi_set-humi)>5)
			switch(humi-humi_set)
			{
				case 10:
					moto_on_add+=5;
					break;
				case 9:
					moto_on_add+=4;
					break;
				case 8:
					moto_on_add+=3;
					break;
				case 7:
					moto_on_add+=2;
					break;
				case 6:
					moto_on_add+=1;
					break;
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
