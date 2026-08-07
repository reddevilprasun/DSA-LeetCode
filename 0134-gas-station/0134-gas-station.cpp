class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tolgas =0;
        int tolcost = 0;
        int start = 0;
        int currgas = 0;
        for(int i = 0; i < gas.size() ; i++) { //O(n)
            tolgas += gas[i];
            tolcost += cost[i];
        }
        if(tolgas < tolcost) return -1;

        for(int i = 0 ; i < gas.size() ; i++) {
            currgas = currgas + gas[i] - cost[i];
            if(currgas < 0) {
                currgas = 0;
                start = i + 1;
            }
        }

        return start;
        
    }
};