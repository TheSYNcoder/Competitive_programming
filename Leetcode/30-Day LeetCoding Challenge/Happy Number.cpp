class Solution {
public:
    bool isHappy(int n) {
        for ( int i =0 ; i < 100000 ; i++ ){
            int res =0;
            while( n > 0){
                int d = n % 10;
                res += d * d;
                n /= 10;
            }
            n = res;
            if ( n == 1)
                break;
        }
        if ( n == 1)return true;
        else return false;
        
    }
};
