#include <queue>

class Stack{
public:
    Stack();
    int top();
    void push(int x);
    void pop();
    int size();
public:
    queue<int> q1, q2;
    int curr_size;
};

Stack::Stack(){ curr_size = 0; }

void Stack::push(int x) {
    curr_size++;
    q2.push(x);

    while (!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
}

void Stack::pop(){
    if (q1.empty()) return;
    q1.pop();
    curr_size--;
}

int Stack::top(){
    if (q1.empty()) return INT_MIN;
    return q1.front();
}

int Stack::size(){
    return curr_size;
}
