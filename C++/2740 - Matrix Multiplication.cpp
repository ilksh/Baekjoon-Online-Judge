#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi multiply(const vvi& A, const vvi& B, int N, int M, int K) {
    vvi result(N, vi(K, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            for (int k = 0; k < M; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M;
    vvi A(N, vi(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    cin >> M >> K;
    vvi B(M, vi(K));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> B[i][j];
        }
    }

    vvi result = multiply(A, B, N, M, K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
