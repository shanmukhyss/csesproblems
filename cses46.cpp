#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
  
    vector<vector<int>>v;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,1,i});
        v.push_back({b+1,-1,i});
   
    }

    sort(v.begin(),v.end());
    int count=0;
    int maxcnt=0;
    vector<int>rooms(n,0);
     priority_queue<int,vector<int>,greater<int>>pq;
     for(auto it:v){
        int type=it[1];
        int id=it[2];
        if(type==1){
            int roomno;
            if(!pq.empty()){
                roomno=pq.top();
                pq.pop();

            }
            else{
                roomno=count++;
            }
            maxcnt=max(maxcnt,count);
            rooms[id]=roomno;
        }
        else{
            pq.push(rooms[id]);
        }
     }

     cout<<maxcnt<<endl;
     for(int i=0;i<n;i++){
        cout<<rooms[i]+1<<" ";
     }
     return 0;
    

    
}