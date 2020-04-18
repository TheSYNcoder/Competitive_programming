class Solution {
public:
    int dp[101][101];
    int rec( string s , int index , int open){
        if ( index == s.length() ) {
            if ( !open) return 1;
            return 0;
        }
        if ( open < 0 ) return 0;
        if ( dp[index][open] !=-1) return dp[index][open];
        if ( s[index] == '('){
            dp[index][open] = rec( s , index+1 ,open+1);
        }
        else if ( s[index] == ')') {
            return dp[index][open] = rec( s, index +1, open -1);
        }
        if ( s[index] == '*'){
            int x = rec( s, index+1 , open +1)|| rec( s, index+1 , open) || rec( s , index +1 ,open -1);
            dp[index][open] = x;
        }
        return dp[index][open];
        
    }
    bool checkValidString(string s) {
        memset( dp ,-1,sizeof(dp));
        if (rec( s , 0 , 0)) return true;
        return false;
    }
};
