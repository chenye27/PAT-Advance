#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct person
{
	char name[9];
	int age;
	int worth;
}p[100010];

struct group{
	int number;
	int min;
	int max;
}g[1010];

bool cmp(person a,person b){
	if(a.worth!=b.worth) return a.worth>b.worth;
	else if(a.age!=b.age) return a.age<b.age;
	else return strcmp(a.name,b.name)<0;
}

int main(int argc, char const *argv[])
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d %d",p[i].name,&p[i].age,&p[i].worth);
	}
	for (int i = 0; i < k; ++i)
	{
		scanf("%d %d %d",&g[i].number,&g[i].min,&g[i].max);
	}
	sort(p,p+n,cmp);
	for (int i = 0; i < k; i++)
	{
		printf("Case #%d:\n",i+1 );
		int len=0;
		for (int j= 0; j <n; j++)
		{
			if (p[j].age>=g[i].min&&p[j].age<=g[i].max)
			{
				printf("%s %d %d\n",p[j].name,p[j].age,p[j].worth );
				len++;
			}
			if (len==g[i].number) break;
			
		}
		if(len==0) printf("None\n");
	}


	return 0;
}