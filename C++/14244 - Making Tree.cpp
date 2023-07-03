#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
   
    vector<int> tree;  // Create a vector to store the tree structure
    int parent = 0;  // Initialize the parent variable to 0

    
    for (int i = 1; i < n; ++i) {// Iterate over the tree nodes
        if (n - m < i) {
            // If the remaining nodes are fewer than m (degree),
            // assign the same parent to the current node
            tree[i] = parent;
        }
        else {
            // If there are more nodes remaining, assign a new parent
            tree[i] = parent;
            parent++;
        }
        
        // Output the parent-child relationship
        cout << tree[i] << " " << i << "\n";
    }
	
    return 0;
}