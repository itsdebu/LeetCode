class Solution {
public:
    
    void dfs(int st, vector<vector<int>>& rooms, vector<bool> &visited){
        visited[st] = true;
        for(int i : rooms[st]){
            if(!visited[i]){
                dfs(i, rooms, visited);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,0);
        
        dfs(0, rooms, visited); 
        for(bool i : visited){
            if(!i)
                return false;
        }
        return true;
    }
};