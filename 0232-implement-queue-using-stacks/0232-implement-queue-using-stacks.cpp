class MyQueue {
public:
stack<int> s1;
stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans=s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
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