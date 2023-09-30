class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>st;
        for(auto it:wordList)st[it]++;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord)return steps;
            for(int i=0;i<word.size();i++)
            {
            string original_word=word;
                for(char j='a';j<='z';j++)
                {
                    word[i]=j;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word=original_word;
            }   
        }return 0;
    }
};