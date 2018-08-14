#include<iostream>
#include<algorithm>
using namespace std;

struct student
{
	int id;
	int p[6];
	int sum;
	int number,number2;
	bool flag;
	
}stu[10010];


bool cmp(student a,student b)
{
	if(a.sum!=b.sum)  return a.sum>b.sum;
	else if(a.number!=b.number)  return a.number>b.number;
	else if (a.id!=b.id)  return a.id<b.id;
}


int main()
{
	int n,k,m;
	int f[6];
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=k;i++){
		scanf("%d",&f[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
			{
				stu[i].p[j]=-1;
			}	
			stu[i].sum=0;
			stu[i].id=i;
	}
	for (int i = 0; i < m; i++)
	{
		int num,l,temp;
		scanf("%d",&num);
		scanf("%d",&l);
		scanf("%d",&temp);
		if(temp>=stu[num].p[l]) {
			if(temp!=-1){
				stu[num].flag=true;stu[num].p[l]=temp;
			}
			else {
				if (stu[num].flag==true)
				{
					stu[num].p[l]=0;
				}
			}
		}


	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (stu[i].p[j]!=-1)
			{
				stu[i].sum += stu[i].p[j];
				if (stu[i].p[j]==f[j])
				{
					stu[i].number++;
				}
			}
			else stu[i].number2++;
		}
	}
	
	sort(stu+1,stu+n+1,cmp);
	int r=1;
	for (int i = 1; i <= n; i++)
	{
		if (stu[i].flag==true)
		{
			if(i>=2){
				if(stu[i].sum==stu[i-1].sum) printf("%d ",r);
				else {printf("%d ", i);r=i;}
			}
		    else printf("%d ", i);
			printf("%05d %d",stu[i].id,stu[i].sum);
			for (int j = 1; j <= k; j++)
			{
				 printf(" ");
				if (stu[i].p[j]!=-1)
				{
					
					printf("%d",stu[i].p[j]);
				}
				else printf("-");
			}
			printf("\n");
		}
		
	}
	return 0;
}