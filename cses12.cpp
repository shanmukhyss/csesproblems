#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'A']++;
    }

    int odd = 0;
    char mid;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            odd++;
            mid = char('A' + i);
        }
    }

    if (odd > 1) {
        cout << "NO SOLUTION";
        return 0;
    }

    string left="";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i] / 2; j++) {
            left+=char('A' + i);
            cout << char('A' + i);
        }
    }

   
    if (odd == 1) {
        cout << mid;
    }

   
    string right= left;
    reverse(right.begin(),right.end());
    cout<<right;

    return 0;
}
