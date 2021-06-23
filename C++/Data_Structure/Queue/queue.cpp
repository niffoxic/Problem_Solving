class Queue{
public:
    explicit Queue(int n);
    void enque(int x);
    void dequeue();
    int getFront();
    int getRear();
    bool isFull();
    bool isEmpty();
    int size();
private:
    int ssize;
    int capacity;
    int *arr;
    int front;
};

Queue::Queue(int n):capacity(n), ssize(0), front(0){
    arr = new int[n];
}

bool Queue::isFull(){ return ssize == capacity; }
bool Queue::isEmpty(){ return ssize == 0; }

void Queue::enque(int x){
    if (isFull()) return;
    int rear = getRear();
    rear = (rear + 1) % capacity;
    arr[rear] = x;
    ssize++;
}

void Queue::dequeue(){
    if (isEmpty()) return;
    front = (front + 1) % capacity;
    ssize--;
}

int Queue::getFront(){
    if (isEmpty()) return INT_MAX;
    return front;
}

int Queue::getRear() {
    if (isEmpty()) return INT_MIN;
    return (front + ssize - 1) % capacity;
}

int Queue::size(){ return ssize; }
