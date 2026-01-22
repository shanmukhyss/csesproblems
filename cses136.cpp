#include<bits/stdc++.h>
using namespace std;
class segment{
    public:
    int n;
    vector<int>seg;
    segment(int n){
        this->n=n;
        seg.resize(4*n);
    } 
    void build(int ind , int low, int high, vector<int>&arr){
        if(low==high){
            seg[ind]=arr[low];
            return ;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
    void update(int ind, int low, int high,int idx, int val){
        if(low==high){
            seg[ind]=val;
            return ;
        }
        int mid=(low+high)/2;
        if(idx>mid){
            update(2*ind+2,mid+1,high,idx,val);
        }
        else{
            update(2*ind+1,low,mid,idx,val);
        }
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
    int query(int ind, int low, int high ,int left, int right){
        if(left<=low && high<=right){
            return seg[ind];
        }
        if(left>high||right<low){
            return INT_MAX;
        }
        int mid=(low+high)/2;
        int l=query(2*ind+1,low,mid,left,right);
        int r=query(2*ind+2,mid+1,high,left,right);
        return min(l, r);

    }
};
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>nxt(n,INT_MAX);
    unordered_map<int ,set<int>>mpp;
    for(int i=0;i<n;i++){
        mpp[v[i]].insert(i);
    }

    for(auto &it:mpp){
        auto &ss= it.second;
        auto curr=ss.begin();
        while(curr!=ss.end()){
            auto p=next(curr);  // BUG FIX 1: moved inside loop and use next()
            if(p!=ss.end()){
                nxt[*curr]=*p;
            }
            curr++;
        }
    }
    segment s(n);
    s.build(0,0,n-1,nxt);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
           int k,u;
           cin>>k>>u;
           k--;
           int old=v[k];
           if(old==u){
             continue;
           }
           auto &st=mpp[v[k]];
           auto itt=st.find(k);
           int prevv = (itt==st.begin())?-1:*prev(itt);
           int nextt = (next(itt)==st.end())?INT_MAX:*next(itt);
           if(prevv!=-1){
              nxt[prevv]=nextt;
              s.update(0,0,n-1,prevv,nxt[prevv]);
           }
           st.erase(itt);  // BUG FIX 2: erase iterator, not *itt
           nxt[k]=INT_MAX;  // BUG FIX 3: update nxt[k] before updating segment tree
           s.update(0,0,n-1,k,INT_MAX);

           auto &s2=mpp[u];
           auto iterator=s2.lower_bound(k);
           int pprev= (iterator==s2.begin())?-1:*prev(iterator);
           int nnext= (iterator==s2.end())?INT_MAX:*iterator;  // BUG FIX 4: use *iterator, not *next(iterator)
           if(pprev!=-1){
             nxt[pprev]=k;
             s.update(0,0,n-1,pprev,nxt[pprev]);
           }
           s2.insert(k);
           nxt[k]=nnext;
           s.update(0,0,n-1,k,nxt[k]);
           v[k]=u;
        }
        else{
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            int value=s.query(0,0,n-1,a,b);
            if(value<=b){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;

}