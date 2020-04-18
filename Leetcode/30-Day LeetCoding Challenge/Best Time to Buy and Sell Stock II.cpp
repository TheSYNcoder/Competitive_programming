class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = 0 , ans =0;
        for ( int i = prices.size() -2 ; i >= 0 ; i--){
            if ( curr > curr + prices[i+1] - prices[i]){
                ans += curr;
                curr =0;
            }
            else curr = curr + prices[i+1] - prices[i];
        }
        if ( curr > 0) ans += curr;
        return ans;
    }
};
