//CODEFORCES 352 B
/*One day Jeff got hold of an integer sequence a1, a2, ..., an of length n. The boy immediately decided to analyze the sequence. For that, he needs to find all values of x, for which these conditions hold:

x occurs in sequence a.
Consider all positions of numbers x in the sequence a (such i, that ai = x). These numbers, sorted in the increasing order, must form an arithmetic progression.
Help Jeff, find all x that meet the problem conditions.

Input
The first line contains integer n (1 ≤ n ≤ 105). The next line contains integers a1, a2, ..., an (1 ≤ ai ≤ 105). The numbers are separated by spaces.

Output
In the first line print integer t — the number of valid x. On each of the next t lines print two integers x and px, where x is current suitable value, px is the common difference between numbers in the progression (if x occurs exactly once in the sequence, px must equal 0). Print the pairs in the order of increasing x.
*/

//A BEAUTIFUL ILLUSTRTION OF DATA PRE PROCESSING

#include <bits/stdc++.h>
#define fie ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,st,end) for(int i=st;i<end;i++)
#define db(x) cout << (#x) << " = " << x << endl;
#define mp make_pair
#define pb push_back
typedef long long int ll;
int main()
{
    fie
    vector< vector<int> > v(1e+5 +9);
    int n ;int p;
     cin >> n;int x;int i,j;
     for( i =0; i < n; i++)
        {
                cin >> x;
                v[x].push_back(i);
        }
    vector<pair<int , int> > ans;
    for ( i =0; i < 1e+5; i++)
    {
        if ( v[i].size() == 0)
            continue;
        else if ( v[i].size() == 1)
            ans.push_back({i, 0});
        else if ( v[i].size() == 2)
            ans.push_back({i , v[i][1] - v[1][0]});
        else
            {
                bool flag = true;
                for ( j =2; j < v[i].size() && flag; j++)
                    if ( (v[i][j]- v[i][j-1]) != (v[i][j-1] - v[i][j-2]) )
                        flag =false;
                if ( flag)
                    ans.push_back({ i , v[i][1]-v[i][0]});
            }
        
    }
    cout << ans.size() << "\n";
    for ( i=0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
    

}
