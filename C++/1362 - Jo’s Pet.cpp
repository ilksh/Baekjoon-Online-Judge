#include<bits/stdc++.h>

using namespace std;


// If its actual weight is more than half but less than twice its optimum weight then the pet is happy
bool isOptimal(double o, double w) {
    return ((0.5 * o < w) && (w < 2 * o));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int cnt = 0;
    
    while (true) {
        double o, w; // o: optimum weight of the pet, w: actual weight
        cin >> o >> w;
        if (o == 0 && w == 0) break;
        bool innnerTerminate = false;
        bool rip = false;
        while (true) {
            char command;
            double weight;
            cin >> command >> weight;
            switch (command) {
                case '#':
                    innnerTerminate = true;
                    break;
                case 'F':
                    w += weight;
                    break;
                case 'E':
                    w -= weight;
                    break;
            }
            if (w <= 0) rip = true;
            if (innnerTerminate) break;
        } // end of command (inner) loop
        cout << ++cnt << ": ";
        if (rip) cout << "RIP" << "\n";
        else {
            string rst = isOptimal(o, w) ? ":-)" : ":-(";
            cout  << rst << "\n";
        }
    }
    return 0;
}
