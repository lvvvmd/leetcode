class Solution {
public:
    bool testCircle(vector<vector<int>>& edges, int end){
        stack<vector<int>> dfs;
        vector<bool> visited(edges.size(), false);
        int startv = edges[end][0], endv =  edges[end][1], curv;
        for(int i = 0;i < end;i++){
            if(edges[i][0] == startv || edges[i][1] == startv){
                dfs.push(edges[i]);
                //break;
            }
        }
        
        curv = startv;
        visited[curv] = true;
        while(!dfs.empty()){
            vector<int> curedge = dfs.top();
            dfs.pop();
            if(curedge[0] == endv || curedge[1] == endv)
                return true;
            else
            {
                if(visited[curedge[0]] == false)
                    curv = curedge[0];
                else
                    curv = curedge[1];
                
                visited[curv] = true;
                
                for(int i = 0;i < end;i++){
                    if((edges[i][0] == curv && visited[edges[i][1]] == false) || (edges[i][1] == curv && visited[edges[i][0]] == false)){
                         dfs.push(edges[i]);
                //break;
            }
        }
                
                
            }
        }
        return false;
        
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> v(edges.size(), 0);
        int numofv = 0;
        for(int i = 0;i<edges.size();i++){
            if(v[edges[i][0]-1] != 0 && v[edges[i][1]-1] != 0 ){
                if(testCircle(edges, i)){
                    return edges[i];
                }
            }
            v[edges[i][0]-1]++;
            v[edges[i][1]-1]++;
        }
        
        return edges[0];
    }
};
