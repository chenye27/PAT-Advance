#include <iostream>
#include <cstring>
using namespace std;


int main(int argc, char const *argv[])
{
	
	char a[10010];
	cin>>a;
	if (a[0]=='-') cout<<a[0];
	
	int cur = 1;
	while(a[cur] != 'E'){
		cur++;
	}
	int k = cur;
	cur++;
	if (a[cur] == '-')
	{
		int l=0;
		cur++;
		for (; cur < strlen(a); cur++)
		{
			l = l * 10 + (a[cur]-'0'); 
		}
		printf("0.");
		l--;
		while(l > 0) {
			cout <<"0";
			l--;
		}
		for (int i = 1; i < k; ++i)
		{
			if (a[i]=='.') ;
			else  cout<<a[i];
		}
	}
	else if (a[cur] =='+')
	{
		int l=0;
		cur++;
		for (; cur < strlen(a); cur++)
		{
			l = l * 10 + (a[cur]-'0');
		}
		if (l > k-3)
		{
			for (int i = 1; i < k; ++i)
			{
				if(a[i] =='.');
				else cout<<a[i];
			}
			for (int i = 0; i < l+3-k; ++i)
			{
				cout<<"0";
			}

		}
		else{
			for (int i = 1; i < k; ++i)
			{
				if (a[i] =='.');
				else if(i==l+2 && i != k-1){
					cout<<a[i];
					cout<<'.';
				}else cout<<a[i];
				
			}



		}


	}
	return 0;
}