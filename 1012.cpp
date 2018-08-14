#include "iostream"

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int a1=0,a2=0,a3=0,a5=0;
	double a4=0.0;
	int b;
	int num2=0,num4=0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&b);
		switch(b%5){
			case 0:a1 += (b%2)?0:b;  break;
			case 1:num2++; 
				if (num2%2) a2 += b; 
				else a2 -= b;         break;
			case 2: a3++;              break;
			case 3: a4 += b ; num4++;break;
			case 4: if(b>=a5) a5 = b;break; 
		}
	}
	if (a1==0) printf("N ");
	else printf("%d ",a1);
	if (num2==0) printf("N ");//对于交错相加，有可能存在结果为0，所以应该用num2做判断
	else printf("%d ",a2);
	if (a3==0) printf("N ");
	else printf("%d ",a3);
	if (num4==0) printf("N ");
	else printf("%.1f ",a4/num4);
	if (a5==0) printf("N");
	else printf("%d",a5);
	return 0;
}