class MyQueue {
public:
stack<int> st;
stack<int> q;
int val;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(st.size()){
            q.push(st.top());
            st.pop();
        }
        int val = q.top();
            q.pop();
        while(q.size()){
            st.push(q.top());
            q.pop();
        }
        return val;
    }
    
    int peek() {
        while(st.size()){
            q.push(st.top());
            st.pop();
        }
        int val = q.top();

        while(q.size()){
            st.push(q.top());
            q.pop();
        }
        return val;
    }
    
    bool empty() {
        while(st.size()) {return false;}
        return true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */