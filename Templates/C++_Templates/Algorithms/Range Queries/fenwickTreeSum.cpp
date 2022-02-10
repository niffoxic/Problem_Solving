// bit takes index + 1
// array takes index
// where index -> 0 to n - 1;

void fenwick(int index, ll val, vector<ll>& bit, vector<ll>& arr)
{
    ll diff = val - arr[index];
    for(int i = index + 1; i <= arr.size(); i += i & (-i))
        bit[i] += diff;
    arr[index] = val;
}

ll getSum(int index, vector<ll>& bit)
{
    ll res = 0;
    for(int i = index; i > 0; i -= i & (-i))
        res += bit[i];
    return res;
}
