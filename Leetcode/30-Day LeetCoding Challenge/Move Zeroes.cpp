class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c= 0 , zeros =0 , n = nums.size();
        for ( int  i = 0; i < n  ; i++){
            if ( !nums[i]){ zeros++ ; continue;}
            nums[c++]= nums[i];
        }
        for ( int i = n-1  ; i > n -1 - zeros ; i--)
            nums[i] =0;
        
    }
};
