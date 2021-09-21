

class kStacks{
public:
    kStacks(int kth, int n);
    bool isFull();
    bool isEmpty(int n);
    void push(int x, int n);
    int pop(int n);
private:
    int *arr;
    int *top;
    int *next;
    int cap, k;
    int freeTop;
};

kStacks::kStacks(int kth, int n): k(kth), cap(n), freeTop(0){
    arr = new int[cap];
    top = new int[k];
    next = new int[cap];

    for(int i = 0; i < k; i++) top[i] = -1;
    for(int i = 0; i < cap - 1; i++) next[i] = i + 1;

    next[cap - 1] = -1;
}

bool kStacks::isFull() { return freeTop == -1; }
bool kStacks::isEmpty(int n) { return top[n] == -1; }

void kStacks::push(int x, int j){
    if (isFull()){ return; }

    int i = freeTop;
    freeTop = next[i];
    next[i] = top[j];
    top[j] = i;
    arr[i] = x;
}

int kStacks::pop(int n){
    if (isEmpty(n)){ return INT_MIN; }

    int i = top[n];
    top[n] = next[i];
    next[i] = freeTop;
    return arr[i];
}
