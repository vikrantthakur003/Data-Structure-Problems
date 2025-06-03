class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dictonary(wordList.begin(), wordList.end());

        if(dictonary.find(endWord) == dictonary.end()){
            return 0;
        }

        int numberOfWords = 1;

        queue<string> q;
        q.push(beginWord);

        while(!q.empty()){
            int size = q.size();

            while(size--){
                string word = q.front();
                q.pop();

                for(int i = 0;i<word.length();i++){
                    char originalChar = word[i];

                    for(char ch = 'a'; ch<='z';ch++){
                        word[i] = ch;

                        if(word == endWord){
                            return numberOfWords + 1;
                        }
                        if(dictonary.find(word) != dictonary.end()){
                            q.push(word);
                            dictonary.erase(word);
                        }
                    }
                    word[i] = originalChar;
                }
            }

            numberOfWords++;
        }

        return 0;
    }
};