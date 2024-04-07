# Stack 

## [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/)
```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> st ; 
        for (int i = 0 ;  i< s.length() ; i++){
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '['){
                st.push(ch) ; 
            }

            else {
                if (!st.empty()){
                    char top = st.top() ;
                    if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                            st.pop() ;
                        }
                        else{
                            return false ; 
                        }
                }
                else{
                    return false ;
                }
            }
        }
        if (st.empty()){
            return true ; 
        }
        return false ;
    }
};
```

## [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/description/)
```c++
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
        int x;
        if(!output.empty()){    // Output has been initialized
            x = output.top();    
            output.pop();
            return x;
        }
        else{
            while(!input.empty()){  // Until input is empty
                output.push(input.top());
                input.pop();
            }
            x = output.top();
            output.pop();
            return x; 
        }   
    }
    
    int peek() {
        if(!output.empty())
            return output.top();
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
           
            return output.top();
        }   
    }
    
    bool empty() {
        return output.empty() && input.empty() ;
    }
};
```