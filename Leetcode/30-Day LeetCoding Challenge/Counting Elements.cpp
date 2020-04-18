class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, int>  m;
        for ( int x :arr) m[x]++;
        int ans = 0;
        for ( auto p : m ){
            if ( m.count(p.first +1 )) ans += p.second;
        }
        return ans;
    }
};
