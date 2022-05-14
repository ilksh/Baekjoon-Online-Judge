#include<iostream>
using namespace std;

int cnt;
int main()
{
	int n;
	cin >> n;
	int change = 1000 - n;

	if (change >= 500)
	{
		cnt += (change / 500);
		change = change % 500;
	}

	if(change >= 100)
	{
		cnt += (change / 100);
		change = change % 100;
	}
	if (change >= 50)
	{
		cnt += (change / 50);
		change = change % 50;
	}
	if (change >= 10)
	{
		cnt += (change / 10);
		change = change % 10;
	}
	if (change >= 5)
	{
		cnt += (change / 5);
		change = change % 5;
	}
	if (change >= 1)
	{
		cnt += (change / 1);
	}
	cout << cnt;
}