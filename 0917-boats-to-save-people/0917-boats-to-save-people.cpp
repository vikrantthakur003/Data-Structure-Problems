class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int s = 0;
        int e = people.size() - 1;

        int noOfBoats = 0;
        while(s<=e){
            if(people[s] + people[e] <= limit){
                s++;
                e--;
            } else if(people[s] + people[e] > limit){
                e--;
            }
            noOfBoats++;
        }

        return noOfBoats;
    }
};