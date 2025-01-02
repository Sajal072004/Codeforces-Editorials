#include"bits/stdc++.h" 
using namespace std; 
#ifdef ONLINE_JUDGE
#define debug(...) 42
#else
#include "puppet.h"
#endif
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define pob pop_back
#define bplc __builtin_popcountll 
#define bpc __builtin_popcount
#pragma GCC optimize("Ofast")
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define unique(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

template<class T> using pbds= tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using min_heap=priority_queue<T, vector<T>, greater<T>>;
// *a.find_by_order(x)-->gives xth element considering 0 indexing
// a.order_of_key(x)-->gives number of elements strictly smaller than x



void solve(){

int n;
cin>>n;
ll a[n];
for(int i=0;i<n;i++)cin>>a[i];
  ll ans=*max_element(a,a+n);
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    for(int k=0;k<n;k++)ans=max(ans,(a[i]|a[j]|a[k]));
  }
}
cout<<ans;

cout<<"\n";

}


int main(){ 



 ios::sync_with_stdio(0);
  cin.tie(0);




 int T=1;
// cin>>T;
while(T--){
    solve();
}




    return 0; 
} 



