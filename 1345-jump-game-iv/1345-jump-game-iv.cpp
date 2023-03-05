class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>> mp;
        
        for(int i=0;i<arr.size();i++)
            mp[arr[i]].push_back(i);

        int ans = -1;
        queue<int> q;
        q.push(0);

        while(q.size()){
            int sz = q.size();
            ans++;
            while(sz--){
                auto idx = q.front(); q.pop();

                if(idx == arr.size()-1) return ans;

                if(idx+1 < arr.size() and mp.count(arr[idx+1]))
                    q.push(idx+1);

                if(idx-1 >= 0 and mp.count(arr[idx-1]))
                    q.push(idx-1);

                for(auto nextIdx : mp[arr[idx]]){
                    if(idx == nextIdx) continue;
                    q.push(nextIdx);
                }

                mp.erase(arr[idx]);
            }
        }

        return ans;
    }
};