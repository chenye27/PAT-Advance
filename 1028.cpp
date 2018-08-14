#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct student{
	int ID;
	char name[9];
	int grade;
}stu[100010];


bool cmp1(student a,student b){
	return a.ID<b.ID;

}
bool cmp2(student a,student b){
	int s= strcmp(a.name,b.name);
	if (s!=0)
	{
		return s<0;
	}
	else return a.ID<b.ID;
}

bool cmp3(student a,student b){
	if (a.grade!=b.grade)
	{
		return a.grade<b.grade;
	}
	else return a.ID<b.ID;

}

int main(int argc, char const *argv[])
{
	int N,C;
	scanf("%d%d",&N,&C);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %s %d",&stu[i].ID,stu[i].name,&stu[i].grade);
	}
	if (C==1)
	{
		sort(stu,stu+N,cmp1);
		for (int i = 0; i < N; ++i)
		{
			printf("%06d %s %d\n",stu[i].ID,stu[i].name,stu[i].grade);
		}
	}
	if (C==2)
	{
		sort(stu,stu+N,cmp2);
		for (int i = 0; i < N; ++i)
		{
			printf("%06d %s %d\n",stu[i].ID,stu[i].name,stu[i].grade);
		}
	}
	if (C==3)
	{
		sort(stu,stu+N,cmp3);
		for (int i = 0; i < N; ++i)
		{
			printf("%06d %s %d\n",stu[i].ID,stu[i].name,stu[i].grade);
		}
	}



	return 0;
}