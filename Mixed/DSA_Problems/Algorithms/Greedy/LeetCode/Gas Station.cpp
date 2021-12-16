class Solution1 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0, temp = 0, check = 0;
        for(int i = 0; i < gas.size(); i++){
            temp += gas[i] - cost[i];
            if (temp < 0){
                res = i + 1;
                temp = 0;
            }
            check += gas[i] - cost[i];
        }
        return (check < 0)? -1: res;
    }
};

class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0, going = 0, fuel = 0;
        while(start < n){
            fuel += gas[going];
            if (fuel >= cost[going]){
                fuel -= cost[going];
                going = (going + 1) % n;
                if (going == start) return start;
            }else{
                fuel = 0;
                going++;
                if (going > start) start = going; else return -1;
            }
        }
        return -1;
    }
};
