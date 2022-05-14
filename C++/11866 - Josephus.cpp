#include<iostream>
#include<queue>

using namespace std;
queue<int> circle;
queue<int> answer;
int n, k;

int main()
{
    cin >> n >> k;

    for(int i=1; i<=n; i++)
        circle.push(i);

    while(answer.size() < n)
    {
        for(int i=0 ; i<k-1; i++)
        {
            int cur = circle.front(); circle.pop();
            circle.push(cur);
        }
        int dead = circle.front(); circle.pop();
        answer.push(dead);
    }

    cout <<"<";
    while(answer.size() >0)
    {
        int temp = answer.front(); answer.pop();
        if(answer.size() ==0)
            cout<<temp;
        else
            cout<< temp <<", ";
    }
    cout <<">";
}
