#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void normalize(vi& a) {
    a.push_back(0);
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] < 0) {
            int borrow = (abs(a[i]) + 9) / 10;
            a[i + 1] -= borrow;
            a[i] += borrow * 10;
        } else {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
    }
    while (a.size() > 1 && a.back() == 0) a.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            c[i + j] += a[i] * b[j];
        }
    }
    normalize(c);
    return c;
}

void addTo(vi& a, const vi& b, int k) {
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); ++i) {
        a[i + k] += b[i];
    }
    normalize(a);
}

void subFrom(vi& a, const vi& b) {
    for (int i = 0; i < b.size(); ++i) {
        a[i] -= b[i];
    }
    normalize(a);
}

vi karatsuba(const vi& a, const vi& b) {
    int an = a.size();
    int bn = b.size();

    if (an < bn) return karatsuba(b, a);

    // Base cases
    if (an == 0 || bn == 0) return vector<int>();
    if (an <= 50) return multiply(a, b);

    int half = an / 2;

    vi a0(a.begin(), a.begin() + half);
    vi a1(a.begin() + half, a.end());
    vi b0(b.begin(), b.begin() + min<int>(b.size(), half)); 
    vi b1(b.begin() + min<int>(b.size(), half), b.end()); 
 
    vi z2 = karatsuba(a1, b1);
    vi z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);

    vi z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vi ret(z0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);

    return ret;
}

vi toVector(long long num) {
    vi result;
    while (num > 0) {
        result.push_back(num % 10);
        num /= 10;
    }
    return result;
}

void printVector(const vi& a) {
    for (int i = a.size() - 1; i >= 0; --i) {
        cout << a[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long S = (long long)N * (N + 1) / 2;

    vi S_vec = toVector(S);

    vi S_squared = karatsuba(S_vec, S_vec);

    cout << S << "\n";         // Sum: 1 + 2 + ... + N
    printVector(S_squared);    // (1 + 2 + ... + N)^2
    cout << "\n";
    printVector(S_squared);    // 1^3 + 2^3 + ... + N^3
    cout << "\n";

    return 0;
}
