#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vector<int> my_list;
long long cnt = 0; // count the number of swap

void swap(int ll, int lr, int rl, int rr) {
    vi temp;
    int start_idx = ll;
    int si = ll, li = rr;

    // merge two sub-list
    while (ll <= lr && rl <= rr) {
        if (my_list[ll] > my_list[rl]) {
            temp.push_back(my_list[rl]);
            cnt += (rl - start_idx);
            rl++;
            start_idx++;
        } else {
            temp.push_back(my_list[ll]);
            ll++;
            start_idx++;
        }
    }

    // copy remained left-sub-list
    while (ll <= lr) {
        temp.push_back(my_list[ll]);
        ll++;
    }

    // copy remained right-sub-list
    while (rl <= rr) {
        temp.push_back(my_list[rl]);
        rl++;
    }

    // copy reversely
    for (int z = li; z >= si; z--) {
        my_list[z] = temp.back(); temp.pop_back();
    }
}

void divide(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;

    divide(l, mid);
    divide(mid + 1, r);

    // merge
    swap(l, mid, mid + 1, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc;
    cin >> tc;

    my_list.resize(tc);
    for (int i = 0; i < tc; ++i) cin >> my_list[i];
    
    divide(0, tc - 1);

    cout << cnt << "\n";

    return 0;
}
