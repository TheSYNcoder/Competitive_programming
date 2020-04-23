class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans= 0 ; 
        int diff=  n -  m;
        for ( int i = 0;  i < 31; i ++ ){
            if ( diff >= ( 1LL << i)) continue;
            int x = ( 1 << i);
            if ( (x & m) && ( x & n))
                ans |= ( 1 << i);
        }
        return ans;
        
    }
};
