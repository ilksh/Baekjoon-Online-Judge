#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vvi multiply(const vvi& A, const vvi& B, int N) {
    vvi result(N, vi(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return result;
}

vvi matrixPower(vvi& A, ll B, int N) {
    if (B == 1) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i][j] %= MOD;
            }
        }
        return A;
    }
    
    vvi half = matrixPower(A, B / 2, N);
    vvi result = multiply(half, half, N);
    
    if (B % 2 == 1) {
        result = multiply(result, A, N);
    }
    
    return result;
}

int main() {
    int N;
    long long B;
    cin >> N >> B;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> result = matrixPower(A, B, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
