class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int unvisited = M.size(), rst = 0;
        vector<bool> visited(unvisited, false);
        while(unvisited != 0){
            int start;
            rst ++;
            for(int i = 0;i < M.size();i++){
                if(visited[i] == false){
                   start = i;    
                    break;
                }
            }
            stack<int> s;
            s.push(start);
            while(!s.empty()){
                
                int now = s.top();
                s.pop();
                visited[now] = true;
                unvisited--;
                for(int j = 0;j<M.size();j++){
                    if(M[now][j] == 1 && visited[j] == false){
                        s.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
        return rst;
    }
};
