//Elaborate solution on the use of DSU for connected components
// Rating : 1500

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define max(x, y) ((x) > (y) ? (x) :(y))
#define pii pair< int , int> 
#define vi vector<int>
#define fr(i, st , en) for ( int i =st; i < en; i++)
const int maxn = 1e6+5;

int par[maxn];
int sz[maxn];
int find( int root){
	return ( par[root] == root  ? root : par[root]=find( par[root]) );
}

int merge( int u , int v){
	par[find(v)] = find(u);
}

int  inc( int x){
	sz[find(x)]+=1;
}

signed main(){
	iota( par, par + maxn  , 0);
	int n;
	cin >> n;
	int edges;
	cin >> edges;
	fr( i , 0 , edges){
		int u , v;
		cin >> u >> v;
		merge( u , v);
	}
	for ( int i = 1 ; i <= n ; i++){
		inc(i);
	}
	int d;
	cin >> d;
	fr( i , 0  , d){
		int u , v;
		cin >> u >> v;
		// same component : delete the component
		if ( find( u) == find(v)){
			sz[find(u)]=0;
		}
	}
	int ans =0;
	for ( int i =1; i <= n; i++){
		ans = max( ans , sz[find(i)]);
	}
	cout << ans;


}
