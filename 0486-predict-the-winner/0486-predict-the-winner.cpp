class Solution {
public:
    bool win(int i,int j,vector<int>&nums,bool turn,int alice , int bob)
    {
        if(i>j)
        {
            return alice>=bob;
        }
        if(turn)
        {
            return win(i+1,j,nums,0,alice+nums[i],bob) or win(i,j-1,nums,0,alice+nums[j],bob);
        }
        else
        {
           return win(i+1,j,nums,1,alice,bob+nums[i]) and win(i,j-1,nums,1,alice,bob+nums[j]);
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        return win(0,n-1,nums,1,0,0);
    }
};