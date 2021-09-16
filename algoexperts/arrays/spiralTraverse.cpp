using namespace std;

vector<int> spiralTraverse(vector<vector<int>> arr) {
	if (arr.size() == 0)
		return {};
	
	vector<int> res;
	int row_start = 0;
	int row_end = arr.size() - 1;
	int col_start = 0;
	int col_end = arr[0].size() - 1;
	
	while (row_start <= row_end && col_start <= col_end){
		for(int i = col_start; i <= col_end; i++){
			res.push_back(arr[row_start][i]);
		}
		
		for(int i = row_start + 1; i <= row_end; i++){
			res.push_back(arr[i][col_end]);
		}
		
		for(int i = col_end - 1; i >= col_start; i--){
			if (row_start == row_end)
				break;
			res.push_back(arr[row_end][i]);
		}
		
		for(int i = row_end - 1; i > row_start; i--){
			if (col_start == col_end)
				break;
			res.push_back(arr[i][col_start]);
		}
		col_start++;
		col_end--;
		row_start++;
		row_end--;
	}
	return res;
}
