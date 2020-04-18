class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int amt = 0 ; 
        for ( auto v : shift ){
            if ( v[0] == 0) amt -= v[1];
            else amt += v[1];
        }
        string t = string( s.size() , '0');
        int n = s.size();
        for ( int i = 0 ; i < n ; i ++ ){
            t[i] = s[ (i - amt + n*100 ) % n ];
        }
        return t;
    }
};
