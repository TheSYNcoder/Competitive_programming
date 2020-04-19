class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0 ;
        if ( nums.size() <= 3){
            for ( int i =0 ; i < nums.size(); i++){
                if ( nums[i] == target) return i;
            }
            return -1;
        }
        int high = nums.size();
        int n= nums.size();
        int mx = 1e8;
        int x =0;
        while( high - low > 0){
            int mid = ( high + low ) /2 ;
            if ( nums[mid] > nums[0]){
                low = mid+1;
            }
            else 
            {
                x =1;
                high = mid;
            }
        }
        int part = low;
        if ( !x) part = n;
        if ( part == 0) part++; 
        int found =-1;
        if ( target > nums[n-1] || !x){
            low = 0; high = part;
            while( high - low > 0 ){
                int mid= ( high + low) /2;
                if ( nums[mid] > target){
                    high =mid;
                }
                else if ( nums[mid] < target){
                    low = mid +1;
                }
                else {
                    found = mid;
                    break;
                }
            }
        }
        else{
            low = part; high = n;
            while( high - low > 0 ){
                int mid= ( high + low) /2;
                if ( nums[mid] > target){
                    high =mid;
                }
                else if ( nums[mid] < target){
                    low = mid +1;
                }
                else {
                    found = mid;
                    break;
                }
            }
            
        }
        return found;
    }
};
