#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAX = 205;
ll INF =  10000000000LL;
ll Capacity[MAX][MAX], Flow[MAX][MAX];
vector<int> Line[MAX]; 

ll MaxFlow(int Sour, int Sink) {
    ll  TotalFlow = 0;

    while (true) {
        vi Parent(MAX, 0);
        queue<int> Queue;

        Queue.push(Sour);
        Parent[Sour] = Sour;

        while (!Queue.empty() && !Parent[Sink]) {
            auto Curr = Queue.front(); Queue.pop();

            for (int Next : Line[Curr]) {
                if (Capacity[Curr][Next] - Flow[Curr][Next] > 0 && !Parent[Next]) {
                    Queue.push(Next);
                    Parent[Next] = Curr;
                    if (Next == Sink) break;
                }
            }
        }

        if (!Parent[Sink]) break;

        ll Amount = INF;
        for (int i = Sink; i != Sour; i = Parent[i]) {
            Amount = min(Amount, Capacity[Parent[i]][i] - Flow[Parent[i]][i]);
        }

        for (int i = Sink; i != Sour; i = Parent[i]) {
            Flow[Parent[i]][i] += Amount;
            Flow[i][Parent[i]] -= Amount;
        }

        TotalFlow += Amount;
    }

    return TotalFlow;
}

int main() {
    int N, M, K, Node;
    cin >> N >> M;

    int Sour = N + M + 1;
    int Sink = N + M + 2;

    vector<ll> CapacityN(N + 1);

    for (int i = 1; i <= N; i++) cin >> CapacityN[i];

    for (int i = N + 1; i < N + M + 1; ++i) {
        long long Cap;
        cin >> Cap;
        Line[Sour].push_back(i);
        Line[i].push_back(Sour);
        Capacity[Sour][i] = Cap;
    }

    for (int i = 1; i < N + 1; ++i) {
        Line[i].push_back(Sink);
        Line[Sink].push_back(i);
        Capacity[i][Sink] = INF;
    }

    for (int i = N + 1; i < N + M + 1; ++i) {
        cin >> K;
        for (int j = 0; j < K; ++j) {
            cin >> Node;
            Line[i].push_back(Node);
            Line[Node].push_back(i);

            if (Node <= N) {
                Capacity[i][Node] = CapacityN[Node];
            } else {
                Capacity[i][Node] = Capacity[Sour][Node];
            }
        }
    }

    cout << MaxFlow(Sour, Sink) << "\n";

    return 0;
}
