long long constructSegmentTree(vector<long long>& arr, vector<long long>& tree, int left, int right, int index){
    if (left == right){
        tree[index] = arr[left];
        return arr[left];
    }
    int mid = left + (right - left) / 2;
    tree[index] = constructSegmentTree(arr, tree, left, mid, index * 2 + 1) +
                  constructSegmentTree(arr, tree, mid + 1, right, index * 2 + 2);
    return tree[index];
}

long long getSum(int rangeLeft, int rangeRight, int left, int right, int index, vector<long long>& tree){
    if (right < rangeLeft || rangeRight < left)
        return 0;
    if (rangeLeft <= left && rangeRight >= right)
        return tree[index];
    int mid = left + (right - left) / 2;
    return getSum(rangeLeft, rangeRight, left, mid, index * 2 + 1, tree) +
           getSum(rangeLeft, rangeRight, mid + 1, right, index * 2 + 2, tree);
}

void updateSegmentTree(vector<long long>& tree, int left, int right, int index, long long diff)
{
    if (index < left || index > right) return;
    tree[index] += diff;
    if (left < right){
        int mid = left + (right - left) / 2;
        updateSegmentTree(tree, left, mid, index * 2 + 1, diff);
        updateSegmentTree(tree, mid + 1, right, index * 2 + 2, diff);
    }
}
