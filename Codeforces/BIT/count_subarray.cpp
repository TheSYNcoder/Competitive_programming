/*
https://codeforces.com/gym/100589/problem/H
Given an array of N integers A 1, A 2 ... A N and an integer K, 
count number of subarrays of A such that number of inversions in those subarrays is at least K.
*/

#include <bits/stdc++.h>
using namespace std; 
#define int long long int
#define max(x, y) ((x) > (y) ? (x) :(y))
#define pii pair< int , int> 
#define vi vector<int>
#define fore( i ,st) for ( int i= 0 ; i < (int)(st) ; i ++)
#define REP( i , st , en ) for ( int i =st; i < (int)en; i++)
#define REPD( i , en , st ) for ( int i =en; i >= (int)st; i--)
#define SZ(a) (int)a.size()
#define all(v) v.begin() , v.end()
#define pb push_back
#define F first
#define S second
#define bug(x) cout <<__LINE__ << ":"<<__FILE__ << " : " <<   #x  << " = " << x << "\n";
#define bitch_i_m_on_fiyaah_yeahhhh ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
ostream& operator << ( ostream&  o, vector<int> s){for ( int i = 0;  i < (int)s.size() ; i++)o << s[i] << " ";o << "\n";return o;}
int  add( int a, int b){int c = a + b; if ( a> mod ) a-= mod; return c;}
void sub( int &a, int b){a = a - b;if ( a < 0) a += mod;}
int mul( int a , int b){return ((a %mod) * (b %mod) ) %mod;}
int exp( int a , int pow){ return (pow == 0 ? 1 : ( pow & 1  ? mul ( a ,exp( mul(a, a) , pow /2) ) : exp(mul(a ,a) , pow/2)));}
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }



const int maxn = 1e5 +5;
int bit[maxn];
// int inv[maxn];
int arr[maxn];


void update( int v, int inc){
	for ( int i =v ; i < maxn; i+= i&-i )
		bit[i]+=inc;
}

int query( int index ){
	int sum =0;
	while( index > 0 ){
		sum += bit[index];
		index -= index & -index;
	}
	return sum;
} 


void compress( int *arr ,int n){
	map<int, int > m;
	vector<int> v( arr , arr + n );
	sort( arr ,arr + n ) ;
	fore(i,n) m[arr[i]]=i+1;
	 
	fore( i , n ) arr[i] = m[v[i]];
}


void solve(int test){
		
	
	int n , k ;
	cin >> n >> k ;
	fore( i , n ) cin >> arr[i];
	if ( k == 0 ){
		cout << (n) *( n+1 ) /2 ;
		return;
	}

	compress( arr, n);
	

	int l = 0 , r =0 ; 
	int inv=0;
	int ans =0;
	update( arr[r] ,1 );
	
	while ( l < n ) {
		while( inv < k && r+1 < n ) {
			
			r++;
			update( arr[r] ,1 );
			inv += r +1  -l  - query(arr[r]);
			 
		}
		
		
		if ( inv < k ) break;
		ans += n- r; 
		
		update( arr[l] , -1 );
		
		inv -= query( arr[l]-1) ;
		
		l++;
		
	}

	cout << ans;


}

signed main(){
	bitch_i_m_on_fiyaah_yeahhhh
	int t =1; 
	// cin >> t;
	for ( int i = 0 ; i < t; i++)
		solve(i+1);
}
