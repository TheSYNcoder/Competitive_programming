class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0 , mx =-INT_MAX;
        for ( int x : nums ){
            sum =sum + x;
            mx = max( mx , sum);
            sum = max( 0 , sum);
        }
        return mx;
    }
};
