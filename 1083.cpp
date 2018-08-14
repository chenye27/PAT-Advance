#include <iostream>
#include <algorithm>
using namespace std;

struct student 
{
	char name[11];
	char id[11];
	int grade;
	
}stu[100010];



bool cmp(student a,student b){
		return a.grade>b.grade;
}

int main(){
	int n,min,max;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%d",stu[i].name,stu[i].id,&stu[i].grade);
	}
	scanf("%d%d",&min,&max);
	sort(stu,stu+n,cmp);
	int len =0;
	for (int i = 0; i < n; i++)
	{
		if (stu[i].grade>=min&&stu[i].grade<=max)
		{
			printf("%s %s\n",stu[i].name,stu[i].id );
			len++;
		}
	}
	if(len==0) printf("NONE\n");

	return 0;
}