#include<bits/stdc++.h>
using namespace std;

class segment{
public:
    int n;
    vector<long long> seg; 
    vector<long long> pref;  

    segment(int n){
        this->n = n;
        seg.resize(4*n);
        pref.resize(4*n);
    }

    void build(int ind, int low, int high, vector<int>& arr){
        if(low == high){
            seg[ind] = arr[low];
            pref[ind] = max(0LL, seg[ind]);
            return;
        }
        int mid = (low + high) / 2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        pref[ind] = max(pref[2*ind+1], seg[2*ind+1] + pref[2*ind+2]);
    }

    void update(int ind, int low, int high, int val, int idx){
        if(low == high){
            seg[ind] = val;
            pref[ind] = max(0LL, seg[ind]);
            return;
        }
        int mid = (low + high) / 2;

        if(idx <= mid)
            update(2*ind+1, low, mid, val, idx);
        else
            update(2*ind+2, mid+1, high, val, idx);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        pref[ind] = max(pref[2*ind+1], seg[2*ind+1] + pref[2*ind+2]);
    }

    pair<long long, long long> queryHelper(int ind, int a, int b, int low, int high){
        if(high < a || low > b)
            return {0, 0}; 

        if(a <= low && high <= b)
            return {seg[ind], pref[ind]};

        int mid = (low + high) / 2;
        auto left = queryHelper(2*ind+1, a, b, low, mid);
        auto right = queryHelper(2*ind+2, a, b, mid+1, high);

        long long totalSum = left.first + right.first;
        long long maxPrefix = max(left.second, left.first + right.second);
        
        return {totalSum, maxPrefix};
    }

    long long query(int ind, int a, int b, int low, int high){
        return queryHelper(ind, a, b, low, high).second;
    }
};

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    segment s(n);
    s.build(0,0,n-1,v);

    while(q--){
        int a;
        cin>>a;
        if(a==1){
            int k,u;
            cin>>k>>u;
            k--;
            s.update(0,0,n-1,u,k);
        }
        else{
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            cout<<s.query(0,a,b,0,n-1)<<endl;
        }
    }
    return 0;
}