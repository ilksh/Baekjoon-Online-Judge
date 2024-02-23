#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int treeSize = 1 << 17;
const int INF = 0x3f3f3f3f;

ll mxTree[treeSize << 1]; // segment tree for maximum
ll mnTree[treeSize << 1]; // segment tree for minimum
int n, m;

int mxQery(int l, int r) {
    ll mx = -1; // intialize maximum to negative: greedy approach

    for (l += treeSize, r += treeSize; l <= r; l >= 1, r >>= 1) {
        if (l & 1) mx = max(mx, mxTree[l++]);

        if (~r&1) mx = max(mx, mxTree[r--]);
    }

    return mx;
}

int mnQery(int l, int r) {
    ll mn = INF; // initialze to infinity 

    for (l += treeSize, r += treeSize; l <= r; l >>= 1, r >> 1) {
        if (l & 1) mn = min(mn, mnTree[l++]);

        if (~r & 1) mn = min(mn, mnTree[r--]);
    }
    
    return mn;
}

void update(int idx, ll x) {
   idx += treeSize;
   mxTree[idx] = x;
   mnTree[idx] = x;

   while(idx >>= 1) {
      mxTree[idx] = max(mxTree[idx << 1], mxTree[idx << 1|1]);
      mnTree[idx] = min(mnTree[idx << 1], mnTree[idx << 1|1]);
   }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(mxTree, 0, sizeof(mxTree));
    memset(mnTree, 0x3f, sizeof(mnTree));
    
    cin >> n >> m;

     for(int i=1; i <= n; ++i) {
      cin >> mxTree[treeSize + i];
      mnTree[treeSize + i] = mxTree[treeSize + i];
    }

    for(int i = treeSize - 1; i > 0; --i) {
        // [0..7] = [0..3] + [4..7]
        mxTree[i] = max(mxTree[i << 1], mxTree[i << 1 | 1]);
        mnTree[i] = min(mnTree[i << 1], mnTree[i << 1 | 1]);
    }

    while(m--) {
        int l, r;

        cin >> l >> r;
        cout << mnQery(l, r) << ' ' << mxQery(l, r) << '\n';
    }

    return 0;
}