#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

int main() {


    int n;
    long long k;
    cin >> n >> k;

    ordered_set s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }

    long long pos = 0;

    while (!s.empty()) {
        pos = (pos + k) % s.size();
        auto it = s.find_by_order(pos);
        cout << *it << " ";
        s.erase(it);
    }

    return 0;
}
