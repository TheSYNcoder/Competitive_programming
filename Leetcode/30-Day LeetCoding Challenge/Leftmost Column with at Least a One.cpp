/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    
    int search( int row ,int m , BinaryMatrix &b){
        int low= 0; int high = m;
        int found =0;
        while( high -low > 0){
            int mid =( high + low ) /2;
            int x = b.get(row , mid);
            if ( !x) low = mid +1;
            else{
                found =1;
                high = mid;
            }
        }
        if ( found) return low;
        else return -1;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &b) {
        vector<int> d = b.dimensions();
        int n = d[0]; int m = d[1];
        int found =-1;
        int mn = m+1;
        for ( int i = 0 ; i < n ; i ++ ){
            int x = search( i ,m , b); 
            if ( x!= -1 ) mn = min( mn , x);
        }
       if ( mn == m+1) return -1;
        return mn;
            
    }
};
