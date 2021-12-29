class cube{
public:
    int h, w, l;
};

bool compare(cube a, cube b){
    return a.w * a.l > b.w * b.l;
}

int maxHeight(int h[], int w[], int l[], int n){
    int len = 3 * n;
    cube arr[len];
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        arr[index].h = h[i];
        arr[index].w = max(w[i], l[i]);
        arr[index].l = min(w[i], l[i]);
        index++;

        arr[index].h = w[i];
        arr[index].w = max(h[i], l[i]);
        arr[index].l = min(h[i], l[i]);
        index++;

        arr[index].h = l[i];
        arr[index].w = max(w[i], h[i]);
        arr[index].l = min(w[i], h[i]);
        index++;
    }

    sort(arr, arr + len, compare);
    int lis[len];
    for(int i = 0; i < len; i++) lis[i] = arr[i].h;
    for(int i = 1; i < len; i++){
        for(int j = 0; j < i; j++){
            if (arr[i].l < arr[j].l && arr[i].w < arr[j].w){
                lis[i] = max(lis[i], lis[j] + arr[i].h);
            }
        }
    }
    int res = *max_element(lis, lis + len);
    return res;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        
        cout<<maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
