#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e2 + 2;
int matrix1[MAX][MAX];
int matrix2[MAX][MAX];
int matrix3[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie( nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for (int row = 0 ; row < n; ++row) {
        for(int col = 0; col < m; ++col) {
            cin >> matrix1[row][col];
        }
    }
    for (int row = 0 ; row < n; ++row) {
        for(int col = 0; col < m; ++col) {
            cin >> matrix2[row][col];
        }
    }

    for (int row = 0 ; row < n; ++row) {
        for(int col = 0; col < m; ++col) {
            matrix3[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }
    for (int row = 0 ; row < n; ++row) {
        for(int col = 0; col < m; ++col) {
            cout << matrix3[row][col] << " ";
        }
        cout << "\n";
    }
    return 0;
}

