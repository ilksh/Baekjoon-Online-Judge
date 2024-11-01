#include<bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef vector<int> vi;

const int MOD = 1e9 + 9;

ll pow(ll x, ll p) {
	ll ret = 1; // result
	ll piv = x;
	while(p) {
		if (p & 1) ret = ret * piv % MOD;
		piv = piv * piv % MOD;
		p >>= 1;
	}
	return ret; 
} 

vi berlekampMassey(vi x) {
	vi ls, cur;
	int lf, ld;

	for (int i = 0; i < x.size(); ++i) {
		ll t = 0;
		for (int j = 0; j < cur.size(); ++j) {
			t = (t + 1ll * x[i - j - 1] * cur[j]) % MOD;
		}
		if ((t - x[i]) % MOD == 0) continue;
		if (cur.empty()) {
			
		}
	}
}
