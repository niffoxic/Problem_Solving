using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
 	int i = 0, j = 0;
	
	while(i < sequence.size() && j < array.size()){
			if(sequence[i] == array[j]){
				i++; j++;
			}else{
				j++;
			}
	}
	
  return sequence.size() == i;
}
