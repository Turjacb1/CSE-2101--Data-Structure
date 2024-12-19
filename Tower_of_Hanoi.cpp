
#include <bits/stdc++.h>
using namespace std;

void towerOfhanoi(int n, char from, char to, char aux)
{
    if (n == 0) {
        return;
    }
    towerOfhanoi(n - 1, from, aux, to);
    cout << "Move " << n << " from " << from
         << " to " << to << endl;
    towerOfhanoi(n - 1, aux, to, from);
}


int main()
{
    int N = 3;

 
    towerOfhanoi(N, 'A', 'C', 'B');
    return 0;
}

