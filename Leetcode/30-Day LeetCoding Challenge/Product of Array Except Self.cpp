class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);      
        vector<int> suff(n);
        for ( int  i = 0 ; i <  n ; i ++ ){
            pre[i] =  nums[i];
            if ( i) pre[i] *= pre[i-1];
        }
        for ( int i =  n-1 ; i >= 0 ; i--) {
            suff[i] = nums[i];
            if ( i!= n-1) suff[i] *= suff[i+1];
        }
        vector<int> out(n);
        for ( int i = 0 ; i  < n ; i ++ ){
            out[i] = (i-1 >= 0 ? pre[i-1] : 1)  * (i+1 < n ? suff[i+1] : 1 );
        }
        return out;
        
            
        
    }
};
