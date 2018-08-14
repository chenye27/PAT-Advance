#include  <iostream>
#include  <algorithm>
using namespace std;
// trick:给出的N个节点可能存在无效节点，所以读取数据后还要遍历一次设置flag

struct NODE{
	int address;
	int date;
	int next;
	bool flag; 
}node[100010];


bool cmp(NODE a, NODE b){
	if (a.flag ==false || b.flag ==false)
	{
		return a.flag > b.flag;
	}else{
		return a.date < b.date;
	}


}
int main(){
	int head,n;
	scanf("%d%d",&n,&head);
	int add;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&add);
		scanf("%d%d",&node[add].date,&node[add].next);
		node[add].address = add;
	}
	int count=0,p=head;
	while(p != -1){
		count++;
		node[p].flag = true ;
		p = node[p].next ;
	}
	if (!count)
	{
		printf("0 -1\n");
	}else{
	sort(node,node+100010,cmp);
	printf("%d %05d\n", count,node[0].address );
	for (int i = 0; i < count ; ++i)
	{
		if (i != count-1)
		{
			printf("%05d %d %05d\n",node[i].address,node[i].date,node[i+1].address);
		}else {
			printf("%05d %d -1\n", node[i].address,node[i].date);
		}
	}}
	return 0;
}