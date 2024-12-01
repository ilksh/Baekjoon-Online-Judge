#include <bits/stdc++.h>

using namespace std;

typedef complex<double> base;
const double PI = acos(-1.0);

void fft(vector<base> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            base w(1);
            for (int j = 0; j < len / 2; j++) {
                base u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (base &x : a)
            x /= n;
    }
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    long long carry = 0;
    for (int i = 0; i < n; i++) {
        long long t = (long long)(fa[i].real() + 0.5) + carry;
        carry = t / 10;
        result[i] = t % 10;
    }

    while (result.size() > 1 && result.back() == 0)
        result.pop_back();
    return result;
}

vector<int> to_vector(const string& num) {
    vector<int> res(num.size());
    for (int i = 0; i < num.size(); ++i)
        res[num.size() - 1 - i] = num[i] - '0';
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string A, B, C;
    cin >> A >> B >> C;

    vector<int> a = to_vector(A);
    vector<int> b = to_vector(B);
    vector<int> c = to_vector(C);

    vector<int> ab = multiply(a, b);

    vector<int> abc = multiply(ab, c);

    string result;
    for (int i = abc.size() - 1; i >= 0; --i)
        result += (char)(abc[i] + '0');

    vector<int> count(10, 0);
    for (char ch : result)
        count[ch - '0']++;

    for (int i = 0; i <= 9; ++i) {
        cout << count[i] << "\n";
    }

    return 0;
}
