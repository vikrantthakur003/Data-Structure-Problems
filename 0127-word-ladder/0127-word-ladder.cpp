class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dictonary(wordList.begin(), wordList.end());

        if(dictonary.find(endWord) == dictonary.end()){
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int numberOfWords = 1;

        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                string frontWord = q.front();
                q.pop();

                for(int i=0;i<frontWord.length();i++){
                    string tempWord = frontWord;

                    for(char ch = 'a'; ch<='z';ch++){
                        tempWord[i] = ch;

                        if(tempWord == endWord){
                            return numberOfWords + 1;
                        }

                        if(dictonary.find(tempWord) != dictonary.end()){
                            q.push(tempWord);
                            dictonary.erase(tempWord);
                        }
                    } 
                }
            }
            numberOfWords++;
        }

        return 0;
    }
};