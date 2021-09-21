class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>weight;
        for(int i = 0; i < dist.size(); i++)
            weight.push_back(ceil(dist[i]/speed[i]));
        int req = 0.0;
        int res = 0;
        for(auto i: weight){
            if (i > req)
                res++;
            else return res;
            req += 1.0;
        }
        return dist.size();
    }
};
