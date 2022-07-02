#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e2 + 2;

int n, m, p;
int A[MAX_N][MAX_N], ret[MAX_N][MAX_N], elem[MAX_N][MAX_N], temp[MAX_N][MAX_N];

void matMul(int (*dest)[MAX_N], int (*src)[MAX_N])
{
    memset(temp, 0, sizeof(temp));
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
        for(int k=0; k<n; ++k) {
            temp[i][j] += dest[i][k] * src[k][j];
            temp[i][j] %= m;
        }
    }

    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
        dest[i][j] = temp[i][j];
    }
}

void myPow() // ret = A^p
{
    memset(ret, 0, sizeof(ret));
    for(int i=0; i<n; ++i) ret[i][i] = 1;
    
    //memcpy(elem, A, sizeof(A));
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
        elem[i][j] = A[i][j];
    }


    for(int i=0; (1 << i) <= p; ++i) {
        if((p >> i) & 1) {
            matMul(ret, elem);
        }
        matMul(elem, elem);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    while(true) {
        cin >> n >> m >> p;
        if(n == 0 && m == 0 && p == 0) break;

        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
            cin >> A[i][j];
        }

        myPow();
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                cout << ret[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    
    return 0;
}

