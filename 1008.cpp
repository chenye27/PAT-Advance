#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int cur=0,time=0;
	for (int i = 0; i < n; ++i)
	{
		int floor;
		cin>>floor;
		if (floor > cur)
		{
			time += 6 * (floor - cur);
			cur = floor;
		}else{
			time += 4 * (cur - floor);
			cur = floor;
		}
		time += 5;

	}
	cout<<time<<endl;
	return 0;
}