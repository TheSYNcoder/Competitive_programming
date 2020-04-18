class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for ( int x : stones) pq.push(x);
        while (true){
            int f = pq.top();
            pq.pop();
            if ( pq.empty()) return f;
            int s = pq.top();
            pq.pop();
            if ( f < s) swap( f , s);
            if ( f > s) pq.push( f -s);
            if  ( f == s){
                if ( pq.empty())return 0;
            }
        }
        
    }
};
