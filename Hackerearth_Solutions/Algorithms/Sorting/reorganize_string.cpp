class Solution {
public:
    string reorganizeString(string &s1) {
        vector<int> arr(26);
        int n = s1.size();
        for(auto i: s1)
            arr[i - 'a']++;
        priority_queue<pair<int, char>> q;
        for(int i = 0; i < 26; i++)
            q.push(make_pair(arr[i], i + 'a'));
        if (q.top().first > (n + 1) / 2)
            return "";
        int i = 0;
        while (!q.empty()){
            int counts = q.top().first;
            char val = q.top().second;
            q.pop();
            for(int j = 0; j < counts; j++){
                if (i > n - 1)
                    i = 1;
                s1[i] = val;
                i += 2;
            }
        }
        return s1;
    }
};
