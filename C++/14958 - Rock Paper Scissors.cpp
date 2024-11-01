#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> cpx;
typedef vector<cpx> vec;

const int MAX = 2 * 1e5 + 2;
const double PI = acos(-1);

string s, t;
int win[MAX];

// In-place FFT function to reduce memory allocation
void FFT(vec& f, bool inv) {
    int n = f.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(f[i], f[j]);
    }
    for (int i = 1; i < n; i <<= 1) {
        double angle = (inv ? PI : -PI) / i;
        cpx w(cos(angle), sin(angle));
        for (int j = 0; j < n; j += i << 1) {
            cpx wp(1, 0);
            for (int k = 0; k < i; k++) {
                cpx temp = f[i + j + k] * wp;
                f[i + j + k] = f[j + k] - temp;
                f[j + k] += temp;
                wp *= w;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) f[i] /= n;
    }
}

// Multiplication function without copying to minimize memory usage
vec multiply(vec& f, vec& g) {
    int n = 1;
    while (n < f.size() + g.size()) n <<= 1;
    f.resize(n), g.resize(n);  // Resize f and g in place
    FFT(f, 0); FFT(g, 0);  // Apply FFT in place
    vec h(n);
    for (int i = 0; i < n; i++) h[i] = f[i] * g[i];
    FFT(h, 1);
    return h;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; 
    cin >> n >> m;
    cin >> s >> t;
    reverse(t.begin(), t.end());

    // Use minimal size coefficient vectors for memory efficiency
    vec a1(n), b1(m), a2(n), b2(m), a3(n), b3(m);

    // Initialize coefficient vectors based on character matches
    for (int i = 0; i < n; i++) {
        a1[i] = (s[i] == 'S'); 
        a2[i] = (s[i] == 'R'); 
        a3[i] = (s[i] == 'P'); 
    }
    for (int i = 0; i < m; i++) {
        b1[i] = (t[i] == 'R'); 
        b2[i] = (t[i] == 'P'); 
        b3[i] = (t[i] == 'S'); 
    }

    // Minimize memory allocation by reusing vectors
    vec r1 = multiply(a1, b1);
    vec r2 = multiply(a2, b2);
    vec r3 = multiply(a3, b3);

    // Calculate the final answer by combining the results
    int ans = 0;
    for (int i = m - 1; i < m + n - 1; i++) {
        win[i] = round(r1[i].real()) + round(r2[i].real()) + round(r3[i].real());
        ans = max(ans, win[i]);
    }
    cout << ans << '\n';
}
