class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, INT_MAX);
        vector<int> currentWordFreq(26, 0);
        
        for(string word : words)
        {
            for(int i = 0; i < 26; i++)
                currentWordFreq[i] = 0;
            
            for(char ch : word)
                currentWordFreq[ch - 'a']++;
            
            for(int i = 0; i < 26; i++)
                minFreq[i] = min(minFreq[i], currentWordFreq[i]);
        }
        
        vector<string> result;
        for(int i = 0; i < 26; i++)
        {
            string currentString = "";
            currentString.push_back(i + 'a');
            
            for(int j = 0; j < minFreq[i]; j++)
                result.push_back(currentString);
        }
        
        return result;
    }
};