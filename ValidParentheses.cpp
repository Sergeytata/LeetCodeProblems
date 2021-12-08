#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.



bool parse(vector<char> s, stack<char> q){
    char head = s.front();
    vector<char> tail = vector<char>( s.begin() + 1, s.end() );
    bool tailIsEmpty = tail.empty();

    switch(head){
        case '(' :
            if(tailIsEmpty) return false;
            q.push(')');
            return parse(tail, q);

        case '{' :
            if(tailIsEmpty) return false;
            q.push('}');
            return parse(tail, q);

        case '[' :
            if(tailIsEmpty) return false;
            q.push(']');
            return parse(tail, q);

        case ')' :
            if(q.empty()) return false;
            if (q.top() == head){
                q.pop();
                if (tailIsEmpty ){
                    if(q.empty()){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                return parse(tail, q);
            }
            else{
                return false;
                }

        case '}' :
            if(q.empty()) return false;
            if (q.top() == head){
                q.pop();
                if (tailIsEmpty ){
                    if(q.empty()){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                return parse(tail, q);
                }
            else{
                return false;
                }

        case ']' :
            if(q.empty()) return false;
            if (q.top() == head){
                q.pop();
                if (tailIsEmpty ){
                    if(q.empty()){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                return parse(tail, q);
                }
            else{
                return false;
                }

    }
    return true;
}

// My slow solution because I heavilly used recurrsion
// always go for simpler solution
bool isValid_slow(string s) {
    vector<char> v(s.begin(), s.end());
    stack<char> q;

    return parse(v, q);
}



// reference solution
// a lot faster and simple
// no need in recursion
bool isValid(string s) {
    stack<char> st;
    for(auto it:s){
        if(it=='('||it=='{'||it=='[') st.push(it);
        else{
            if(!st.size()) return false;
            char ch=st.top();
            st.pop();
            if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
            else return false;
        }
    }
    return st.empty();
}



// main to run tests for different inputs
int main(int argc, char const *argv[])
{
    cout << "Valid Parentheses Problem" << endl;
    stack<char> q;

    if (!q.empty()){
        cout << q.top() << endl;
    }
    else{
        cout << "Queue is empty" << endl;
    }
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "([{}])";
    string s4 = "{[]}";
    string s5 = "[";
    string s6 = "]";
    string s7 = "([)]";
    string s8 = "([]";

    cout << (isValid(s1) == 1) << endl;
    cout << (isValid(s2) == 1) << endl;
    cout << (isValid(s3) == 1) << endl;
    cout << (isValid(s4) == 1) << endl;
    cout << (isValid(s5) == 0 )<< endl;
    cout << (isValid(s6) == 0) << endl;
    cout << (isValid(s7) == 0) << endl;
    cout << (isValid(s8) == 0) << endl;

    return 0;
}
