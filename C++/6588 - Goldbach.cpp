#include <iostream>
using namespace std;
const int MAX_N = 1e6+1;

bool deleted[MAX_N];

void eratosthenes()
{
    for (int i = 2; i <= MAX_N; i++)
    {
        if (deleted[i])
            continue;
        for (int j = i + i; j <= MAX_N; j += i)
        {
            deleted[j] = true;
        }
            
    }
}

void goldbach(int data)
{
    for (int i = 3; i <= data; i++)
    {   
        // censoring prime number
        if (!deleted[i] && !deleted[data - i]) 
        {
            cout << data << " = " << i << " + " << (data - i) << "\n";
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong." << "\n";
    return;
}

int main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(NULL);
    eratosthenes();

    while (true)
    {
        int num;
        cin >> num;
        if (num == 0)
            break;
        goldbach(num);
    }
    return 0;
   
}