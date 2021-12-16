#include <vector>
#include <unordered_map>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions, vector<int> results) {
  // Write your code here.
	// 1 -> home team won : 0 -> away team won;
	unordered_map<string, int> res;
	int ans = -1;
	string team;
	for(int i = 0; i < competitions.size(); ++i){
		if (results[i]){
			res[competitions[i][0]] += 3;
			ans = max(ans, res[competitions[i][0]]);
		}else{
			res[competitions[i][1]] += 3;
			ans = max(ans, res[competitions[i][1]]);
		}
		
	}
	int curr = -1;
	for (auto i: res){
		if (curr < i.second){
			team = i.first;
			curr = i.second;
		}
	}
  return team;
}
