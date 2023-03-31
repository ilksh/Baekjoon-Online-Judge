#include<bits/stdc++.h>

using namespace std;

int aCard[11];       // Sequence of Card for player A
int bCard[11];       // Sequence of Card for player B
int aPoint, bPoint;  // intial point is zero
char winner = NULL;  // Winner of the game
char lastWinner = NULL;

bool isFinish(int point) {
  return point == 13;
}

bool isAllTie() {
  for (int i = 0; i < 10; ++i) {
    if (aCard[i] != bCard[i]) return false;
  }
  return true;
}

void solve() {
  for (int i = 0 ; i < 10; ++i) {
    auto diff = aCard[i] - bCard[i];
      if (diff > 0) {
        aPoint += 3; // Card from A is bigger
        lastWinner = 'A';
      }
      else if (diff == 0) { // tie
        aPoint++;
        bPoint++;
      }
      else{
        bPoint += 3; // Card from B is bigger
        lastWinner = 'B';
      }
      if (winner) continue; // when the winner is already revealed.
        
      if (isFinish(aPoint) + isFinish(bPoint) == 2) winner = lastWinner;
      if (isFinish(aPoint)) winner = 'A';
      if (isFinish(bPoint)) winner = 'B';
    }
    cout << aPoint << " " << bPoint << "\n";
    if (isAllTie()) cout << "D\n";
    else cout << winner << "\n";
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(nullptr);
    
  for (int i = 0; i < 10; ++i) cin >> aCard[i];
  for (int i = 0; i < 10; ++i) cin >> bCard[i];
  solve();
  return 0;
}
