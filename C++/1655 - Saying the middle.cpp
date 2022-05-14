#include<iostream>
#include<queue>
#include<vector>
using namespace std;

priority_queue <int> max_heap;
priority_queue <int> min_heap;
queue<int> answer;
int median;

int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	int temp;
	cin >> n;

	for(int i=0; i<n; i++)
	{
		int data;
		cin >> data;
		if (i==0)
		{
			median = data;
			max_heap.push(data);
		}
			
		else
		{
			if (data <= median)
				max_heap.push(data);
			else if (data > median)
				min_heap.push(-data);
			
			int total_size = min_heap.size() + max_heap.size();

			// number of data is odd
			if (total_size % 2 == 1)
			{
				if (min_heap.size() > max_heap.size())
				{
					temp = -min_heap.top(); min_heap.pop();
					max_heap.push(temp);
				}
				median = max_heap.top();
				
			}

			// number of data is even
			else if(total_size%2 == 0)
			{
				if (min_heap.size() > max_heap.size())
				{
					temp = -min_heap.top(); min_heap.pop();
					max_heap.push(temp);
				}

				else if (min_heap.size() < max_heap.size())
				{
					temp = max_heap.top(); max_heap.pop();
					min_heap.push(-temp);
				}

				median = max_heap.top();
			}
		}
		//cout << median << "\n";
		answer.push(median);
	}

	while (!answer.empty())
	{
		cout << answer.front() << "\n";
		answer.pop();
	}
	return 0;
	
}