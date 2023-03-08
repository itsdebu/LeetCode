class Solution {
    
    bool canEat(vector<int>& piles, int h, int k)
    {
        int numHoursUsed = 0;
        for(const auto& numBanana : piles)
        {
            if (numBanana%k == 0)
            {
                numHoursUsed += numBanana/k;
                
            }
            else
            {
                numHoursUsed += numBanana/k+1;
                
            }
            if (numHoursUsed > h)return false;
            
        }
        return true;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
              
        int hi = *max_element(piles.begin(), piles.end());
        int lo = 1;
        int best = hi;
        while(lo <= hi)
        {
            int m = (lo+hi)/2;
            if (canEat(piles, h, m))
            {
                best = m;
                hi = m - 1;
            }
            else
            {
                lo = m +1;
            }
            
        }
        return best;
        
    }
};