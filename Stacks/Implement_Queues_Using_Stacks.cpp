#include<iostream>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;
class MyQueue {
public:
stack<int> input;
stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int val= output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};
// Use two stacks:
// input → stores newly pushed elements.
// output → provides elements in FIFO order.

// push():
// Simply push the new element into input.

// pop():
// If output is empty, transfer all elements from input to output.
// This reverses the order, putting the oldest element on top.
// Then pop the top element from output.

// peek():
// If output is empty, transfer all elements from input to output.
// Return output.top().

// empty():
// Queue is empty only when both input and output are empty.

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */