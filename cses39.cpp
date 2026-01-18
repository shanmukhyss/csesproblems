#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    cin >> x >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    multiset<long long> gaps;
    gaps.insert(x);

    set<long long> s;
    s.insert(0);
    s.insert(x);

    for(int i=0; i<n; i++){
        auto itr=s.upper_bound(v[i]);
        auto itl=prev(itr);
        
        gaps.erase(gaps.find(*itr - *itl));
        
        gaps.insert(v[i] - *itl);
        gaps.insert(*itr - v[i]);
        s.insert(v[i]);

        cout << *gaps.rbegin() << " ";
    }

    return 0;
}