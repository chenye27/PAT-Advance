#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	long long a[n],b[n],c[n];
	bool flag[n];
	for (int i = 0; i < n; ++i)
	{
		long long res;
		cin>>a[i]>>b[i]>>c[i];
		res = a[i] + b[i]; 
		if (a[i] > 0 && b[i] > 0 && res < 0) flag[i] =true;
		else if(a[i] < 0 && b[i] < 0 && res >= 0) flag[i] = false;//此处res>=0,等号要取到。100000+100000=1000000，值为0；
		else if( res > c[i]) flag[i] = true;
		else flag[i] = false;
	}

	for (int i = 0; i < n; ++i)
	{
		if (flag[i]==true)
		{
			cout<<"Case #"<<i+1<<": true"<<endl;
		}else cout<<"Case #"<<i+1<<": false"<<endl;
	}
	return 0;
}