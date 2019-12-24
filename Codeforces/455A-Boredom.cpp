/*input
9
1 2 1 3 2 2 2 2 3
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int maxn =4e5+5;
const int val =26;
int arr[maxn];
int dp[maxn][2];
signed main(){
	int n;
	cin >> n;
	int mz =0;
	for ( int i =1 ; i <= n ; i++)
		{
			int x;
			cin >> x;
			arr[x]++;
			mz = max( mz , x);
		}
	
	for ( int i =1 ; i <= maxn-1; i++){
		dp[i][0] = dp[i-1][1];
		dp[i][1] = max( dp[i-1][1]  ,dp[i-1][0]+ arr[i] *i );
	}
	cout << max( dp[mz][0] , dp[mz][1]);

}
