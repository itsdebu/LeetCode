class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st(wordList.begin(),wordList.end());

        queue<pair<string,int>>q;

        q.push({beginWord,1});
        
        while(!q.empty())
        {
            string curr_word = q.front().first;
            int steps = q.front().second;

            q.pop();

            if(curr_word == endWord)return steps;

            for(int i=0;i<curr_word.size();i++)
            {
                string temp_word = curr_word;
                for(char ch='a';ch<='z';ch++)
                {
                    temp_word[i] = ch;
                    if(st.find(temp_word)!=st.end())
                    {
                        q.push({temp_word,steps+1});
                        st.erase(temp_word);
                    }
                    // temp_word = curr_word;
                }
            }
        }
        return 0;
    }
};