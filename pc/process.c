/*************************************************************************
	> File Name: /mnt/share/process.c
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2022年03月21日 星期一 14时19分58秒
 ************************************************************************/

#include<stdio.h>

void moto_on()
{

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
	int temp,tmp2,humi;
	int temp_set,water_set,humi_set;
	int moto_ustime=0,relay_ustime=0,led_ontime=0;
	while(1)
	{
		if(temp<temp_set)
		{
			if((temp_set-temp)>1)
			switch(temp-temp_set)
			{
				case -2:
					cnt_timer_add+=1;
					break;
				case -3:
					cnt_timer_add+=2;
					break;
				case -4:
					cnt_timer_add+=3;
					break;
				case -5:
					cnt_timer_add+=4;
					break;
				case -6:
					cnt_timer_add+=5;
					break;
			}
		}

/*****************************湿度调整设置****************/		
		if(humi<humi_set)
		{

			if((humi_set-humi)>5)
			{
				relay_on();
				switch((int)((humi-humi_set)/5))
				{
					case -1:
						cnt_timer_add-=1;
						water_on_add+=1;
						break;
					case -2:
						cnt_timer_add-=2;
						water_on_add-=2;
						break;
					case -3:
						cnt_timer_add-=3;
						water_on_add-=3;
						break;
					case -4:
						cnt_timer_add-=4;
						water_on_add-=4;
						break;
					case -5:
						cnt_timer_add-=5;
						water_on_add-=5;
						break;
					case -6:
						cnt_timer_add-=6;
						water_on_add-=6;
						break;
					case -7:
						cnt_timer_add-=7;
						water_on_add-=7;
						break;
					case -8:
						cnt_timer_add-=8;
						water_on_add-=8;
						break;
				}
			}
		}
		if(humi>humi_set)
		{
			if((humi-humi_set)>5)
			switch(humi-humi_set)
			{
				case 10:
					moto_on_add+=5;
					water_on_add+=9;
					cnt_timer_add+=5;
					break;
				case 9:
					moto_on_add+=4;
					cnt_timer_add+=5;
					break;
				case 8:
					moto_on_add+=3;
					cnt_timer_add+=5;
					break;
				case 7:
					moto_on_add+=2;
					cnt_timer_add+=5;
					break;
				case 6:
					moto_on_add+=1;
					cnt_timer_add+=5;
					break;
			}
		}
/*****************土壤湿度处理***************************/		
		if(tmp2<water_set)
		{
			relay_on();
		}
		if(tmp2>=water_set)
		{
			~relay_on();
			if(((int)(tmp2-water_set))>15)
			switch((int)((water_set-tmp2)/10))
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
			}
		}

/***********************开关操作处理**********************/				
		if(water_on_add==1500)
		{
			relay_on();
			water_on_add=0;
			relay_ustime++;
		}
		if(cnt_timer_add==30000)
		{
			led_on;
			led_ontime++;
			cnt_timer_add=0;

		}
		if(moto_on_add==100)
		{
			moto_on();
			moto_ustime++;
			moto_on_add=0;
		}

/************************************************/		
		if(relay_ustime>0)
		{
			relay_bit++;
			if(relay_bit==60)
			{
				~relay_on;
				relay_bit=0;
				relay_ustime=0;
			}

		}
/************************************************/		
		if(moto_ustime>0)
		{
			moto_bit++;
			if(moto_bit==10)
			{
				~moto_on;
				moto_ustime=0;
				moto_bit=0;
			}
		}
/************************************************/		
		/*
		if(led_ontime>0)
		{
			led_bit++;
			if(led_bit==20)
			{
				~led_on;
				led_ontime=0;
				led_bit=0;
			}
		}
		*/

	}
}
