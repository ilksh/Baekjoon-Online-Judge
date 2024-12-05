#include<bits/stdc++.h>

using namespace std;

const int MAX = 3000 + 3;
int tc; 

void normalize(string& sequence) {
    vector<string> subtrees[MAX];
    int depth = 0;

    for (char symbol : sequence) {
        if (symbol == '0') {
            depth++;
        } else {
            string subtree = "0";
            sort(subtrees[depth].begin(), subtrees[depth].end());

            for (auto& elem : subtrees[depth]) {
                subtree += elem;
            }
            
            subtree += "1";
            subtrees[depth].clear();
            depth--;
            subtrees[depth].emplace_back(subtree);
        }
    }

    sequence.clear();
    sort(subtrees[0].begin(), subtrees[0].end());
    for (const auto& subtree : subtrees[0]) {
        sequence += subtree;
    }
    subtrees[0].clear();
}

void ahu() {
    string seqOne, seqTwo; 
    cin >> seqOne >> seqTwo;

    normalize(seqOne);
    normalize(seqTwo);

    cout << (seqOne == seqTwo ? 1 : 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tc;
    while (tc--) {
        ahu();
    }
}
