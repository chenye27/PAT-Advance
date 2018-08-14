#include <iostream>
#include <string>
using namespace std;

int n;

string dealwith(string str, int& e)
{
	int k=0;
	while(str.length() > 0 && str[0]=='0'){
			str.erase(str.begin());
	}
	if (str[0]=='.')
	{
		str.erase(str.begin());
		while(str.length() > 0 && str[0]=='0'){
			str.erase(str.begin());
			e--;
		}

	}else {
		while(k < str.length() && str[k]!= '.')
		{
			k++;
			e++;
		}
		if (k< str.length())
		{
			str.erase(str.begin()+k);
		}
	}
	if(str.length()==0) e=0;

	int num=0;
	k=0;
	string res;
	while(num<n){
		if (k<str.length())
		{
			res += str[k++];
		}
		else  res += '0';

		num++;
	}

		return res;
}
int main()
{
	
	string a,b,c,d;
	cin >> n >> a >> b;
	int e1=0,e2=0;
	c = dealwith(a,e1);
	d = dealwith(b,e2);
	if (c == d && e1 == e2){
		cout<<"YES 0."<<c<<"*10^"<<e1<<endl;
	}else{
		cout<<"NO 0."<<c<<"*10^"<<e1<<" 0."<<d<<"*10^"<<e2<<endl;
	}

	return 0;
}