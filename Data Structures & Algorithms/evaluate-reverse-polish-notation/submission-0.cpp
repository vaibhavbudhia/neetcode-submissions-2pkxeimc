class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        st.push(tokens[0]);
        for(const string& s : tokens){
            if(s=="+"){
                string val = st.top();
                st.pop();
                int ans = stoi(st.top())+stoi(val);    
                st.pop();
                st.push(to_string(ans));
            }
            else if(s=="-"){
                string val = st.top();
                st.pop();
                int ans = stoi(st.top())-stoi(val);    
                st.pop();
                st.push(to_string(ans));
            }
            else if(s=="*"){
                string val = st.top();
                st.pop();
                int ans = stoi(st.top())*stoi(val);    
                st.pop();
                st.push(to_string(ans));
            }
            else if(s=="/"){
                string val = st.top();
                st.pop();
                int ans = stoi(st.top())/stoi(val);    
                st.pop();
                st.push(to_string(ans));
            }
            else st.push(s);
        }
        return stoi(st.top());
    }
};
