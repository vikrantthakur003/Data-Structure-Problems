class Solution {
public:
    vector<string> result;
    unordered_map<string, bool> mp;

    void solve(int ind, string &s, string temp){
        if(ind >= s.length()){
            result.push_back(temp);
            return;
        }

        for(int i = ind; i<s.length(); i++){
            string newStr = s.substr(ind, i - ind + 1);
            if(mp.find(newStr) != mp.end()){
                int newIndex = i + 1;
                int len = temp.length();

                if(!len){
                    temp = newStr;
                } else {
                    temp += " " + newStr;
                }
                solve(newIndex, s, temp);

                temp.resize(len);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for(int i = 0; i<wordDict.size(); i++){
            mp[wordDict[i]] = true;
        }

        solve(0, s, "");

        return result;
    }
};