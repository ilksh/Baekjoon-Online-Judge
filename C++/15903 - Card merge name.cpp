#include <iostream>

using namespace std;

const int MAX_N = 1e3 + 3;

typedef long long ll;

int n, m;
int x;

template<typename T>
class priority_queue {
private:
   int cnt;
   T heap[MAX_N];

public:
   int size() {
      return cnt;
   }

   priority_queue() {
      cnt = 0;
   }

   void swap(int a, int b) {
      T temp = heap[a];
      heap[a] = heap[b];
      heap[b] = temp;
   }

   void push(T item) {
      heap[++cnt] = item;

      int cur = cnt;
      while(cur > 1) {
         int par = cur >> 1;
         if(heap[cur] <= heap[par]) break;

         swap(cur, par);
         cur = par;
      }
   }

   void pop() {
      heap[1] = heap[cnt--];

      int cur = 1;
      while(cur <= cnt) {
         int left = (cur << 1) <= cnt ? (cur << 1) : -1;
         int right = (cur << 1 | 1) <= cnt ? (cur << 1 | 1) : -1;
         int child = cur;

         if(left == -1) break;

         if(heap[cur] < heap[left]) {
            child = left;
         }

         if(right != -1 && heap[child] < heap[right]) {
            child = right;
         }

         if(child == left) {
            swap(cur, left);
            cur = left;
         }
         else if(child == right) {
            swap(cur, right);
            cur = right;
         }
         else {
            break;
         }
      }
   }

   bool empty() {
      return cnt == 0;
   }

   T top() {
      return heap[1];
   }
};

int main()
{
   priority_queue<ll> pq;

   cin >> n >> m;
   for(int i=0; i<n; ++i) {
      cin >> x;
      pq.push(-1*x);
   }

   while(m--) {
      ll a = -1 * pq.top(); pq.pop();
      ll b = -1 * pq.top(); pq.pop();

      a += b;
      pq.push(-1*a);
      pq.push(-1*a);
   }

   ll ret = 0;
   while(!pq.empty()) {
      ret += -1*pq.top(); pq.pop();
   }

   cout << ret << '\n';
   return 0;
}
