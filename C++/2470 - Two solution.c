#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long int result_min = 987654321987654321;
int final_left, final_right;
int arr[100000];

void two_solution(int left, int right, int data[])
{
    int imsi, result_temporary;

    if(left==right)
        return;

    result_temporary = data[left]+ data[right];
    imsi = abs(result_temporary);

    if(imsi < result_min)
    {
        result_min = imsi;
        final_left = left;
        final_right = right;
    }

    if(result_temporary > 0)
        two_solution(left, right-1, arr);
    if(result_temporary < 0)
        two_solution(left+1,right, arr);
}

int main()
{
    long long int n;

    scanf("%lld", &n);
    for(int i=0; i<n ;i++)
        scanf("%d", &arr[i]);

    sort(arr,arr+n);

    two_solution(0,n-1,arr);

    printf("%d ", arr[final_left]);
    printf("%d", arr[final_right]);


}
