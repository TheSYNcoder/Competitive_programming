class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int ,int> m;
        int sum = 0 , ans =0;
        m[0] =1;
        for ( int x : nums){
                sum += x;
                if  (m.count(sum-k)) ans += m[sum-k];
                m[sum]++;
        }
        return ans;
    }
};
