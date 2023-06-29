class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int keys = 0;
        int sx = -1;
        int sy = -1;
        for(int i =0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if(grid[i][j] == '@'){
                    sx = i;
                    sy = j;
                    break;
                }
            }
        }
        cout<<sx <<" "<<sy<<endl;

        for(int i =0;i<rows;i++){
            for(int j =0;j<cols;j++){
                int temp = grid[i][j];
                if(temp >= 97 && temp <= 122 ){
                    keys++;
                }
            }
        }
        cout<<keys<<endl;
        map<pair< set<int>, pair<int,int>> , int> vis;
        vector<int> vecR = {0,-1,0,1};
        vector<int> vecC = {1,0,-1,0};
        set<int> s;
        queue<pair<pair<int,int>, set<int>>> q;
        q.push({{sx,sy},s});
        vis[{s,{sx,sy}}] = 1;
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front().first.first;
                int j = q.front().first.second;
                s = q.front().second;
                cout<<s.size();
                q.pop();
                int temp = grid[i][j];
                if(temp >= 97 && temp<=122) s.insert(temp);
                if(s.size() == keys) return count;
                for(int p  = 0; p<4 ; p++){
                    int newRow  = i + vecR[p];
                    int newCol = j + vecC[p];
                    if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols){
                        continue;
                    }
                    else{
                        int x = grid[newRow][newCol];
                        if(x == 35) continue;
                        if(x >= 65 && x <= 90){
                            if(s.find(x + 32) == s.end()){
                                continue;
                            }
                        }
                    
                        if(vis[{s,{newRow,newCol}}] != 1){
                            vis[{s,{newRow,newCol}}] =1;
                            q.push({{newRow,newCol},s});
                        }
                    }
                }

            }
            count++;

        }

        return -1;
    }
};