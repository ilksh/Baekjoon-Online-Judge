#include<iostream>

using namespace std;

int time[1001];
int person[1001];
int result;

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int n; cin>> n;
    for(int i=0; i<n; i++)
        cin >> time[i];

    for(int i=0; i<n;i++)
    {
        for(int j=i+1; j<n;j++)
        {
            if(time[i] > time[j])
                swap(time[i], time[j]);
        }
    }

   int idx=1;

   for(int i=0; i<n; i++)
   {
       for(int j=0; j<idx; j++)
            person[i]+=time[j];
       idx++;
   }

   for(int i=0; i<n; i++)
        result += person[i];

    cout<<result;
}
