#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;
    while(q--){
        long long k;
        cin>>k;

        long long len = 1;
        long long count = 9;
        long long start = 1;

        while(k > len * count){
            k -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }

        long long num = start + (k - 1) / len;
        string s = to_string(num);
        cout << s[(k - 1) % len] << endl;
    }
}
