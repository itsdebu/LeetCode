class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix){
            
       int row=matrix.size(),val=0;
       if(row==0)return 0; 
            
       int col=matrix[0].size(); 
       int n=col;    
       vector<int> heights(n);  
            
       for(int i=0;i<row;i++){
               
           for(int j=0;j<col;j++){
              if(matrix[i][j]=='1'){
                 if(i!=0 && matrix[i-1][j]=='1')heights[j]++;
                 else heights[j]=1;
              }
              else heights[j]=0;    
           }
   
         stack<int> st;   
         vector<int> rs(n);
         vector<int> ls(n);
            
         for(int i=n-1;i>=0;i--){
                 
             while(!st.empty() && heights[i]<=heights[st.top()])st.pop();
             
             if(st.empty())rs[i]=n;
             else rs[i]=st.top();
           
             st.push(i);
         }   
         
         while(!st.empty())st.pop();   
            
          for(int i=0;i<n;i++){
                 
             while(!st.empty() && heights[i]<=heights[st.top()])st.pop();
             
             if(st.empty())ls[i]=-1;
             else ls[i]=st.top();
           
             st.push(i);
         } 
            
         int ans=0;  
         for(int i=0;i<n;i++){
             int base=rs[i]-ls[i]-1;
             ans=max(ans,min(heights[i],base));
         }   
          val=max(val,ans);     
       }  
       
    return val*val ; 
    }
};