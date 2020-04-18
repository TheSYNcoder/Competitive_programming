class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int ,int > m;
        int sum =0 ; 
        m[0] = 0;
        int mx = 0;
        for ( int i =1; i  <= nums.size() ; i++){
            if ( nums[i-1] == 1 ) sum += 1;
            else sum -= 1;
            if ( m.count(sum)){
                mx = max( mx , i - m[sum]);
            }
            else 
            m[sum] = i;
        }
        return mx;
        
    }
};
