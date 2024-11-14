#include<stdio.h>
#define pi 3.1415
int main()
{
	float r=12.25/(2*pi);
	float stron=pi*r*r;
	float sthang=(58+23)*30/2;
	float kq=sthang-stron;
	printf("dien tich san truong tuong lai:%.2f(m^2)",kq);
	return 0;
}
