#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int maxn =4e5+5;
const int val =26;

vector<int> segTree[maxn];

void build( string s,int v, int l , int r){
	if ( l == r) {
		segTree[v][s[l] -'a']++;
		return;
	}
	int tm = ( l+ r ) >> 1;
	build( s, 2*v , l , tm);
	build( s, 2*v +1 , tm+1 , r);
	for ( int i =0; i < 26 ; i++){
		segTree[v][i] = segTree[2*v][i] + segTree[2*v+1][i];
	}

}
void update( string &s, int v, int pos , char c , int l , int r){
	
	if ( l ==    r){
		segTree[v][s[l] - 'a']--;
		segTree[v][c-'a']++;
		return;
	}
	int tm = ( l + r) >> 1;
	if (pos<= tm)
	update( s, 2*v , pos , c , l , tm);
	else
	update( s, 2*v+1 , pos , c , tm+1 , r);
	segTree[v].clear();
	segTree[v].resize(26,0);
	for ( int i =0 ; i < 26; i++){
		segTree[v][i] = segTree[2*v][i] + segTree[2*v+1][i];
	}
}

int helper( vector<int> h){
	int cnt =0;
	for ( int i =0;  i < 26; i++){
		if ( h[i] > 0){
			cnt++;	
		}
	}
	
	return cnt;
}
vector<int> combine( vector<int> a , vector<int> b){
	vector<int> ret(26, 0);
	
	for ( int i =0; i < 26; i++){
		if ( b[i]) ret[i]+=b[i];
		if( a[i]) ret[i]+=a[i];
	}
	return ret;
}
vector<int>  query( int v,  int tl , int tr, int l  , int r){
	if ( l > r)return vector<int> (26, 0);
	if ( tl == l && tr == r){
		return (segTree[v]);
	}
	int tm =( tl + tr ) >> 1;
	return combine( query( 2*v , tl , tm , l, min(r, tm)), 
	 query( 2*v+1 , tm+1 , tr , max(l , tm+1 ) , r));

}

int res( int v,  int tl , int tr, int l  , int r){
	vector<int> h = query( v,  tl ,  tr,  l  , r);
	return helper(h);
}
signed main()
{
	// Won't get AC without this :)
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
		string s;
		cin >> s;
		int n =s.length();
		int q;
		for ( int i =0; i < maxn ; i++){
			segTree[i].resize( 26 , 0);
		}
		build(s , 1 , 0 , n-1);
		cin >> q;
    	for ( int i =0 ; i < q; i++){
    		int x;
    		cin >> x;
    		// cout << x << " " << s << "\n";
    		if ( x == 1){
    			int pos;
    			char c;
    			cin >> pos >> c;
    			pos--;
    			update( s , 1 , pos , c , 0 , n-1);
    			s[pos]=c;
    		}
    		else{
    			int l , r;
    			cin >> l >> r;
    			l--;r--;
    			cout << res(1 , 0 , n-1 ,l , r) << "\n";
    		}
    	}

}
