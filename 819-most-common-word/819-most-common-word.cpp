class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

	for(auto&c : paragraph)
		c = ispunct(c) ? ' ' : tolower(c);

	string str, res;
	unordered_map<string, int> freq;
	unordered_set<string> b(banned.begin(), banned.end());
	stringstream ss(paragraph);

	while(ss>>str)
		if(b.count(str)==0 && freq[res]<++freq[str]) 
			res = str;

	return res;
}
};