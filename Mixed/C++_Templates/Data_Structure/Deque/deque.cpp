

class Deque{
public:
    Deque(int size);
    void insertFront(int x);
    void insertRear(int x);
    void deleteFront();
    void deleteRear();
    int getFront();
    int getRear();
    int size();
    bool isFull();
    bool isEmpty();
private:
    int currentSize;
    int *arr;
    int capacity, front;
};


Deque::Deque(int n):currentSize(0), capacity(n), front(0){
    arr = new int[capacity];
}

bool Deque::isEmpty() { return currentSize == 0; }
bool Deque::isFull(){ return currentSize == capacity; }
int Deque::size(){ return capacity; }

void Deque::deleteFront() {
    if (isEmpty()) return;
    front = (front - 1) % capacity;
    currentSize--;
}

void Deque::insertRear(int x){
    if (isFull())
        return;
    int cr = (front + currentSize) % capacity;
    arr[cr] = x;
    currentSize++;
}

int Deque::getFront() {
    if (isEmpty()) 
       return INT_MIN;
    return front;
}

void Deque::insertFront(int x){
    if (isFull()) return;
    front = (front + capacity - 1) % capacity;
    arr[front] = x;
    currentSize++;
}

void Deque::deleteRear(){
    if (isEmpty()) return;
    currentSize--;
}

int Deque::getRear() {
    if (isEmpty()) return INT_MAX;
    return (front + currentSize - 1) % capacity;
}
