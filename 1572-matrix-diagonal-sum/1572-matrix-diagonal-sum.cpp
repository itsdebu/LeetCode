class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        if(mat.size()==1)return mat[0][0];
        int sum=0;
        for(int i=0;i<mat.size();i++)
        {
            sum+=mat[i][i];
        }
        int j=mat.size()-1;
        for(int i=0;i<mat.size();i++)
        {
            sum+=mat[j][i];
            j--;
        }
        if(mat.size()%2!=0)
        {
            sum-=mat[mat.size()/2][mat.size()/2];
        }return sum;
    }
};