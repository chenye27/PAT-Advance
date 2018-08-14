#include <iostream>
#include <algorithm>
using namespace std;

struct student
{
	int GE,GI,sum;
	int w[5];
	int r,stuid;
}stu[40010];

struct school
{
	int qu,number;
	int id[40010];
	int last;

}sch[100];


bool cmp1(student a,student b){
  	if(a.sum!=b.sum)return a.sum>b.sum;
  	else return a.GE>b.GE;
}

bool cmp2(int a,int b){
 		return  stu[a].stuid<stu[b].stuid;
}


int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 0; i < m; i++)
	{
		scanf("%d",&sch[i].qu);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d",&stu[i].GE,&stu[i].GI);
		stu[i].sum=stu[i].GE+stu[i].GI;
		stu[i].stuid=i;
		for (int j = 0; j< k ; j++)
		{
			scanf("%d",&stu[i].w[j]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		sch[i].number=0;
	}
	sort(stu,stu+n,cmp1);
	int r1=0;
	stu[0].r=0;
	for (int i = 1; i < n; i++)
	{
		if(stu[i].sum==stu[i-1].sum&&stu[i].GE==stu[i-1].GE){
			stu[i].r=r1;
		}
		else {stu[i].r=i;r1=i;}
	}
	int num=0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int l=stu[i].w[j];
			if (sch[l].number<sch[l].qu)
			{
				sch[l].last=stu[i].r;
				sch[l].id[num++]=i;
				sch[l].number++;
				break;
			}
			else if(stu[i].r==sch[l].last) {
				sch[l].id[num++]=i;
				sch[l].number++;
				break;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		sort(sch[i].id,sch[i].id+sch[i].number,cmp2);
		for (int j = 0; j < sch[i].number; j++)
		{
			printf("%d ", sch[i].id[j]);
		}
		printf("\n");
	}

}