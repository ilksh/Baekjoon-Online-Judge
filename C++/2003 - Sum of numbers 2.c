#include<stdio.h>

int n, data[10001];
long long int m, sum;
int cnt;

void sum_check(int left, int right)
{
    sum= data[1];

    while(left<=n)
    {
        if(sum == m)
            cnt++;
        if(sum <= m && right < n)
            sum += data[++right];
        else
            sum-=data[left++];
    }
}

int main()
{
    scanf("%d %lld", &n, &m);

    int i;

    for(i=1;i<=n;i++)
        scanf("%d", &data[i]);
    sum_check(1,1);
    printf("%d",cnt);
}

