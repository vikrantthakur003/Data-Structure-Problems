class Solution {
public:
    void generateAdjacenZeros(int n, int index, vector<string>& result, string temp){
        if(index >= n){
            result.push_back(temp);
            return;
        }

        generateAdjacenZeros(n, index + 1, result, temp + '1');

        if(temp.empty() || temp[temp.size() - 1] == '0'){
            generateAdjacenZeros(n, index + 1, result, temp + '1');
        }
    }

    void generateBinaryUsingQueue(int n, vector<string> &result){
        queue<string> q;
        q.push("0");
        q.push("1");

        while(!q.empty()){
            string temp = q.front();
            q.pop();

            if(temp.size() == n){
                result.push_back(temp);
            } else{
                q.push(temp + '1');
                if(temp[temp.size() - 1] == '1'){
                    q.push(temp + '0');
                }
            }
        }
    }
    vector<string> validStrings(int n) {
        vector<string> result;
        string temp = "";
        generateBinaryUsingQueue(n, result);
        // generateAdjacenZeros(n, 0, result,temp);
        return result;
    }
};