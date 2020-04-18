class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss ,tt ;
        int count =0;
        for ( int i = s.length()   -1;  i >= 0 ; i--){
            if ( s[i ] == '#') count++;
            else{
                if ( count > 0){
                    count--;
                    continue;
                }
                ss.push_back(s[i]);
                
            }
        }
        count = 0 ; 
        for ( int i = t.length()  -1; i >= 0 ;  i -- ) {
            
            if ( t[i] == '#' )count++;
            else{
                if ( count > 0){
                    count--;
                    continue;
                }
                tt.push_back( t[i]);
            }
        }
        if ( ss == tt) return true;
        return false;
    }
};
