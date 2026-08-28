class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
    }

    void push(int x) {
        while(!q1.empty()){ //till not empty
            q2.push(q1.front()); //copy q1 elemnts to q2
            q1.pop(); //pop q1
        }
        q1.push(x); //now push new elemnt to q1

        while(!q2.empty()){ //till copy q2 is not empty
            q1.push(q2.front()); //push q2 to q1 after new elemnt
            q2.pop(); //pop q2 
        }
    }

    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */