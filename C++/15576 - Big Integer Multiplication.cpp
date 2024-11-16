#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

typedef complex<double> base;
typedef vector<base> vb;

const double PI = acos(-1.0);

void fft(vb &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        while (j >= bit) {
            j -= bit;
            bit >>=1;
        }
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len < n + 1; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            base w(1);
            for (int j = 0; j < len / 2; ++j) {
                base u = a[i + j];
                base v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (base &x : a) x /= n;
    }
}

vi multiply(const vi& a, const vi& b) {
    vb fa(a.begin(), a.end());
    vb fb(b.begin(), b.end());

    int n = 1;
    int mxSize = a.size() + b.size();
    while (n < mxSize) n <<= 1;

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < n; ++i) fa[i] *= fb[i];

    fft(fa, true);

    vi result(n);
    ll carry = 0;

    for (int i = 0; i < n; ++i) {
        ll t = (ll) (fa[i].real() + 0.5) + carry;
        carry = t / 10;
        result[i] = t % 10;
    }

    while (result.size() > 1 && result.back() == 0) result.pop_back();

    return result;
}

vi toVector(const string& num) {
    int n = num.size();
    vi result(n);
    for (int i = 0; i < n; ++i) {
        int curIdx = n - i - 1;
        result[curIdx] = num[i] - '0';
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    string A, B;
    cin >> A >> B;

    vi a = toVector(A);
    vi b = toVector(B);

    vi result = multiply(a, b);
    int n = result.size() - 1;
    for (int i = n; i >= 0; --i) cout << result[i];
    
    cout << "\n";
    return 0;
}