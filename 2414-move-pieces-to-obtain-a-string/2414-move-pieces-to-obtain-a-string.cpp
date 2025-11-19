class Solution {
public:
    bool canChange(string start, string target) {
        
        vector<int> startL;
        vector<int> startR;
        vector<int> targetL;
        vector<int> targetR;

        for(int i = 0; i<start.length(); i++){
            if(start[i] == 'L'){
                startL.push_back(i);
            } else if(start[i] == 'R'){
                startR.push_back(i);
            }
        }

        for(int i = 0; i<target.length(); i++){
            if(target[i] == 'L'){
                targetL.push_back(i);
            } else if(target[i] == 'R'){
                targetR.push_back(i);
            }
        }

        if (startL.size() != targetL.size()) return false;
        if (startR.size() != targetR.size()) return false;

        for(int i = 0; i<startL.size(); i++){
            if(startL[i] < targetL[i]){
                return false;
            }
        }

         for(int i = 0; i<targetR.size(); i++){
            if(startR[i] > targetR[i]){
                return false;
            }
        }


        string str1 = "";
        string str2 = "";
        for(int i = 0; i<start.size(); i++){
            if(start[i] != '_'){
                str1.push_back(start[i]);
            }
        }

        for(int i = 0; i<target.size(); i++){
            if(target[i] != '_'){
                str2.push_back(target[i]);
            }
        }

        return str1 == str2;
    }
};