class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string , vector<string> > m;
        for ( string s : strs){
            string t = s;
            sort( t.begin() , t.end());
            m[t].push_back(s);
        }
        vector< vector<string > > ret;
        for ( auto p : m ){
            ret.push_back(p.second);
        }
        return ret;
        
        
    }
};
