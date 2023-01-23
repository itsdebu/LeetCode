class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1, 0);
        for(auto vec : trust){
            indegree[vec[0]]--;
            indegree[vec[1]]++;
        }
        for(int i = 1; i<=n; i++)
            if(indegree[i] == n-1)
                return i;
        return -1;
    }
};