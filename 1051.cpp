#include <iostream>
#include <stack>
using namespace std;
//模拟一次进栈操作，容量超出及跳出循环，当s.top()为序列当前数值时进行出栈操作，并且数组下标加一，
//最后判断条件：若成功按照序列进出栈，栈空，且标记依旧为true，其余情况皆为失败。


stack<int> s;
int main()
{
	int m,n,k;
	cin>>m>>n>>k;
	int a[n];
	for (int i = 0; i < k; i++)
	{
		while(!s.empty()){					//上一次判断后可能导致栈非空，所以每次开始必须初始化栈；
			s.pop();
		}
		for (int j = 0; j < n; j++)
		{
			cin>>a[j];
		}

		int cur=0;
		bool flag =true;
		for (int j = 1; j <= n; j++)
		{
			s.push(j);
			if (s.size()>m)		//此处的stack容量判断必须放在while前面，否则报错；
			{
				flag=false;
				break;
			}
			while(!s.empty()&&s.top()==a[cur]){
				s.pop();
				cur++;
			}
			
		}
		if (s.empty()&&flag)
		{
			cout<<"YES"<<endl;

		}else cout<<"NO"<<endl;

	}
	return 0;
}