#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<long long, int> freq;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        freq[x]++;  
    }

    cout << freq.size() << "\n";  
    return 0;
}
