#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 3e2 + 2;
int arr[MAX_SIZE][MAX_SIZE];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n , m;
    cin >> n >> m;
    
    for(int row = 0 ; row< n ; ++row){
        for(int col = 0 ; col < m; ++col){
            cin >> arr[row][col];
        }
    }
    int k;
    cin >> k;
    int i, j, x, y;
    
    for (int a = 0; a < k; a++) {
            cin >> i >> j >> x >> y;
            int sum = 0;
            for (int b = i - 1; b < x; b++) {
                for (int c = j - 1; c < y; c++) {
                    sum += arr[b][c];
                }
            }
        cout << sum << "\n";
        }

    return 0;


}

