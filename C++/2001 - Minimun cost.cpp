#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;

priority_queue <float> pasta;
priority_queue <float> juice;

int main()
{
	int a;

	for (int i = 0; i < 3; i++)
	{
		cin >> a;
		pasta.push(-a);
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> a;
		juice.push(-a);
	}

	float result = -pasta.top() + -juice.top();
	result *= 1.1;

	printf("%.1f", result);
}
