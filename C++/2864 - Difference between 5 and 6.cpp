#include<iostream>
#include<string>
using namespace std;

string num1, num2;

int main()
{
	cin >> num1 >> num2;

	for (int i = 0; i < num1.length(); i++)
	{
		if (num1[i] == '6')
			num1[i] = '5';
	}
	for (int i = 0; i < num2.length(); i++)
	{
		if (num2[i] == '6')
			num2[i] = '5';
	}
	int min_value = stoi(num1) + stoi(num2);

	for (int i = 0; i < num1.length(); i++)
	{
		if (num1[i] == '5')
			num1[i] = '6';
	}
	for (int i = 0; i < num2.length(); i++)
	{
		if (num2[i] == '5')
			num2[i] = '6';
	}
	int max_value = stoi(num1) + stoi(num2);

	cout << min_value << " " << max_value;
}