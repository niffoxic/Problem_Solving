#include <iostream>
using namespace std;

class stack{
public:
    stack(int x);
    bool push(long long x);
    long long pop();
    long long peek();
    int size();
    bool isEmpty();
    long long *array;
private:
    int capacity;
    int top;
};

stack::stack(int x): capacity(x), top(-1){
    array = new long long[capacity];
}

bool stack::push(long long x){
    if (top + 1 == capacity){
        return false;
    }
    top++;
    array[top] = x;
    return true;
}

long long stack::pop(){
    if (top == -1){
        return 0;
    }
    long long result = array[top];
    top--;
    return result;
}

long long stack::peek(){
    if (top == - 1){
        return 0;
    }
    return array[top];
}

int stack::size(){
    return top + 1;
}

bool stack::isEmpty(){
    return top == -1;
}
