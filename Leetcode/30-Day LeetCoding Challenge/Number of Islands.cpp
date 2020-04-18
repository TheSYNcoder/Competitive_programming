class Solution {
public:
    int ok( int x , int y , int r  , int c){
        return ( x < r && x >=0 && y >= 0 && y < c);
    }
    int numIslands(vector<vector<char>>& grid) {
        if ( grid.empty()) return 0;
        int rows = grid.size(); int cols = grid[0].size();
        int ans =0 ;
        int dx[4]= { 0 , 0 , 1,  -1};
        int dy[4] = {1 ,-1 , 0 , 0};
        vector< vector <bool> > vis( rows , vector<bool>( cols , false));
        for  (int i = 0; i  < rows; i++){
            for ( int j = 0 ; j < cols; j++){
                if ( grid[i][j] == '1' && !vis[i][j]){
                    queue< pair <int, int> > q;
                    q.push({ i , j});
                    ans++;
                    while( !q.empty()){
                        pair< int, int > p = q.front(); q.pop();
                        vis[p.first][p.second] = true;
                        for ( int k = 0 ; k < 4; k++){
                            int nx = p.first + dx[k];
                            int ny = p.second + dy[k];
                            if ( ok( nx , ny ,rows , cols) && !vis[nx][ny] && grid[nx][ny] == '1'){
                            vis[nx][ny]=true; q.push({nx,ny});}
                        }
                    }
                }
            }
        }
        return ans;
    }
};
