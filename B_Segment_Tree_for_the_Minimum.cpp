#include<bits/stdc++.h>
using namespace std;
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define endl   '\n' 
const ll N = 1e5 + 7;
const ll mx = 1e9+9;

 ll a[N];
 //ll t[4*N];
 pair<int,int>t[4*N];
 void build(int node , int b, int e) {
    if(b == e) {
       // t[node] = a[b]; 
       t[node].first = a[b];
       t[node].second = 1;
        return;
    }
    //cout << t[node].first << " " << t[node].second;

    int l = 2 * node, r = 2 * node + 1;

    int mid = (b+e)/2;

    build(l,b,mid);
    build(r,mid+1,e);

   // t[node] = min(t[l] , t[r]);
   if(t[2*node] < t[2*node+1]) {
        t[node].first = t[2*node].first;
        t[node].second = t[2*node].second;
 
   }
   else if(t[2*node+1] < t[2*node] ) {
        t[node].first = t[2*node+1].first;
        t[node].second = t[2*node+1].second;
   }
   else {
        t[node].first = t[2*node].first;
        t[node].second = t[2*node].second + t[2*node+1].second;
   }
    

 }

pair<int,int> query(ll node , int b, int e, int i , int j) {

    if(b > j or e < i) return {mx,-1};
    if(b >= i and e <= j)return t[node];

    int l = 2 * node , r = 2 * node + 1;

    int mid = (b+e)/2;

    pair<int,int>q1 = query(l,b,mid,i,j);
    pair<int,int>q2 = query(r,mid,e,i,j);
     pair<int,int>q;

     if(q1.first < q2.first) {
        q = q1;

     }
     else if(q2.first < q1.first) {
        q = q2;
     }
     else {
        q.first = q1.first;
        q.second = q1.second + q2.second;
     }


   // return min(query(l,b,mid,i,j) , query(r,mid+1,e,i,j));
  
  return q;



}

 void update(int node , int b, int e, int i, int x) {

        if(b > i or e < i) return;

        if(b == e and b == i) {
            t[node].first = x; 
            t[node].second = 1;
            return;
        }

        int l = 2 * node , r = 2 * node + 1;

        int mid = (b+e) / 2;

        update(l, b ,mid , i,x);
        update(r, mid+1, e, i, x);

        //t[node] = min(t[l], t[r]);

        if(t[2*node] < t[2*node+1]) {
        t[node].first = t[2*node].first;
        t[node].second = t[2*node].second;
 
   }
   else if(t[2*node+1] < t[2*node] ) {
        t[node].first = t[2*node+1].first;
        t[node].second = t[2*node+1].second;
   }
   else {
        t[node].first = t[2*node].first;
        t[node].second = t[2*node].second + t[2*node+1].second;
   }


 }

int main() {
    faster;
 
  ll n, m; cin >> n >> m;

  for(ll i = 1; i <=n; i++) {
     cin >> a[i];
  }
  build(1,1,n);
  // cout << t[1].first << " " << t[1].second << endl;
//   cout << t[1] << endl;
//   cout << query(1,1,n,1,3) << endl;
  //update(1,1,n,1,10);
   //cout << query(1,1,n,1,3) << endl;
while(m--) {
    int q ; cin >> q;
    if(q == 1) {
        int i , v; cin >> i >> v;
        update(1,1,n,i+1,v);
    }
    else {
        int l , r; cin >> l >> r;
        pair<int,int>ans = query(1,1,n,l+1,r);
        cout << ans.first << " " << ans.second << endl;
    }
}
return 0;
}