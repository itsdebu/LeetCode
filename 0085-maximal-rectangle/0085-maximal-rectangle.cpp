class Solution {
public:
    int MAH(vector<int>& arr) {
        vector<int> left, right;
        stack<int> stk;
        int n=arr.size();
        
		//smallest element in the left
        for(int i=0;i<n;++i){
            int cur = arr[i];
            while(!stk.empty() && arr[stk.top()]>=cur) stk.pop();
            if(stk.empty()) left.push_back(-1);
            else left.push_back(stk.top());
            stk.push(i);
        }
        
        while(!stk.empty()) stk.pop();
        
		//smallest element in the right
        for(int i=n-1;i>=0;--i){
            int cur = arr[i];
            while(!stk.empty() && arr[stk.top()]>=cur) stk.pop();
            if(stk.empty()) right.push_back(n);
            else right.push_back(stk.top());
            stk.push(i);
        }
        reverse(right.begin(),right.end());
        
        int area=0;
        for(int i=0;i<n;++i){
            area=max(area, arr[i]*(right[i]-left[i]-1));
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size(), result=0;
        vector<int> histogram(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    histogram[j]+=1;
                else
                    histogram[j]=0;
                
                // cout<<histogram[j]<<" ";
            }
            // cout<<endl;
            result = max(result, MAH(histogram));
            // cout<<result<<" ";
        }
        return result;
    }
};