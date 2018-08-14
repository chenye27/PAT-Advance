#include <iostream>


struct Node{
	char letter;
	int next;
	bool flag;
}node[100000];




int main(){
	
	int head1,head2;
	int n;
	int add;
	scanf("%d%d%d",&head1,&head2,&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&add);
		scanf(" %c %d", &node[add].letter,&node[add].next);
		//不可以写成scanf("%d %c %d",&add,&node[add].letter,&node[add].next)
		//因为这条语句执行完add才会被赋值，所以此时add为不确定值，发生数组下标越界，段错误。
		node[add].flag=false;
	}
	int l=head1;
	while(l!= -1){
		node[l].flag=true;
		l=node[l].next;
	}

	l=head2;
	while(l!= -1){
		
		if (node[l].flag==true) break;
		else l =node[l].next;
	}


	if (l!=-1)
	{
		printf("%05d\n", l);
	}
	else printf("-1\n");

return 0;


}