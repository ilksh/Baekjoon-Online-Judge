#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // x-y coordinate

const int MAX = 2000000000;

int N;
vector<pii> arr;

// get the distance between two points
int distance(int ptOne, int ptTwo) {
    int lowX = arr[ptOne].first;
    int lowY = arr[ptOne].second;

    int highX = arr[ptTwo].first;
    int highY = arr[ptTwo].second;

    int distX = highX - lowX;
    int distY = highY - lowY;
    
    return distX * distX + distY * distY;
}

// using binary search to find the closest pair
int bst(int low, int high) {
    if (low == high) return MAX;
    if (low + 1 == high) return distance(low, high);

    int mid = (low + high) / 2;
    int distMin = min(bst(low, mid), bst(mid + 1, high)); // recursive call

    // middle area's minimum distance
    vector<pii> inner;
    int lineX = arr[mid].first;

    for (int i = mid; i >= low; --i) { // left area
        int x = arr[i].first;
        int dist = lineX - x;
        if (dist * dist >= distMin) break;
        inner.emplace_back(arr[i].second, arr[i].first); // {y, x}
    }

    for (int i = mid + 1; i <= high; ++i) { // right area
        int x = arr[i].first;
        int dist = lineX - x;
        if (dist * dist >= distMin) break;
        inner.emplace_back(arr[i].second, arr[i].first); // {y, x}
    }

    // if no valid points found, return the current minimum distance
    if (inner.empty()) return distMin;

    // sort by y coordinate
    sort(inner.begin(), inner.end());

    for (int i = 0; i < inner.size(); ++i) {
        for (int j = i + 1; j < inner.size(); ++j) {
            int dy = inner[j].first - inner[i].first;
            if (dy * dy >= distMin) break;

            int dx = inner[j].second - inner[i].second;
            int dist = dx * dx + dy * dy;
            distMin = min(distMin, dist);
        }
    }
    return distMin;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());
    cout << bst(0, N - 1) << "\n";
    return 0;
}
