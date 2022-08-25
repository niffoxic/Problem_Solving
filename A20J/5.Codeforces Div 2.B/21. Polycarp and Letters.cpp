#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    unordered_map<char, int> mp;
    int res = 0;
    for(int i = 0; i < n; i++){
        if (mp.find(s[i]) == mp.end() && s[i] > 95) mp[s[i]] = i;
        else if (s[i] < 95) mp.clear();
        else if (mp.find(s[i]) != mp.end()){
            if (mp[s[i]] == -1) mp[s[i]] = i;
            else{
                for(auto p: mp){
                    if (p.second < i) mp[p.first] = -1;
                }
                mp[s[i]] = i;
            }
        }
        res = max(res, (int)mp.size());
    }
    return cout << res, 0;
}
