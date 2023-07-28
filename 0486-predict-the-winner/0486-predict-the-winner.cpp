class Solution {
public:
    
    // Player1 turn adds score and Player2's turn deducts score
    // Game result = max score of Player1 - max score of Player2
    // dp vector tracks the game result in range l to h => max array length 20
    int dp[21][21]={};
    
    int takeStone(bool Player, int l, int h, vector<int>& nums)
    {
        // base cases : impossible and so return -1 as scores are non-negative
        if(l>h) return -1;
        
        // l==h return the score
        if(l==h) return nums[l];
        
        // return precalculated result
        if(dp[l][h]!=-1) return dp[l][h];
        
        // Player1's turn, Player1 can take either nums[l] or nums[h] so we add them with the recursion call as
        // nums[l]+takeStone(l+1,h) or nums[h]+takeStone(l,h-1) and get the max value betweeen them 
        // for getting the game result as Player1 always tries to maximize his score
        if(Player)    
            dp[l][h] = max(nums[l]+takeStone(!Player,l+1,h,nums),nums[h]+takeStone(!Player,l,h-1,nums));
        
        // Player2's turn, choice for Player2 is same as Player1, only differece is that Player2 wants to maximize his
        // game result by minimizing Player1's result and so we return the min value between those two choices
        // also to get game result we deduct nums[l] or nums[h] with recursion calls
        else
            dp[l][h] = min(-nums[l]+takeStone(!Player,l+1,h,nums),-nums[h]+takeStone(!Player,l,h-1,nums));

        return dp[l][h];
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        
        // Player1 turn = true, Player2 turn = false
        // Game result = max score of Player1 - max score of Player2
        // If result >= 0 then Player1 wins
			return takeStone(true,0,n-1,nums) >= 0; // Incase of draw Player1 wins
    }
};