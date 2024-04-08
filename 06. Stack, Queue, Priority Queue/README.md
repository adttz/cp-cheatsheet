# Stack / Queue & Priority Queue

# Table of Contents
**[Stack](#stack)**
- [Functions](#functions)
- [Monotonic Stack](#monotonic-stack)

**[Queue](#queue)**

**[Priority Queue](#priority-queue)**


# Stack
```c++
template <class T, class Container = deque<T> > class stack;
```
- Container classes vector/deque/list (deque by default)
- LIFO (Last in, first out)

#### Functions
```c++
stack<int> s;
s.push(2);
s.push(3);
s.push(5);
s.top(); // Points to the last / newest element
while(!s.empty()){
    cout << s.top() << endl;    // 5 3 2
    s.pop();
}
```
#### Monotonic Stack
- Stack whose elements are monotonically increasing or decreasing
- Used for 
    - previous/next - smaller/larger 
    - calculating the maximum area under histograms
    - evaluating expressions with infix to postfix conversion
    - stock span, building and trapping rainwater, etc.


<details>
        <summary> Next Greater Element </summary>
    <pre><code lang="c++">
class Solution
{
    public:
    vector < int > nextLargerElement(vector< int > arr, int n)
    {
        stack < int > s;
        vector < int > ans(n);
        for (int i = n-1; i >= 0; i--)
        {
            //while element at top of stack is less than or equal to
            //current array element, we pop elements from the stack.
            while (!s.empty () and s.top () <= arr[i])
                s.pop ();
            
            if (s.empty ()){    //if stack becomes empty, we store -1 in the answer list 
                ans[i] = -1;
            }
            else{               //else we store the top element of the stack.
                ans[i] = s.top();
            }
            s.push (arr[i]);
        }
        //returning the list.
        return ans;
    }
};
    </code></pre>
</details>  

<details>
        <summary>Nearest Smaller Values</summary>
    <pre><code lang="c++">
void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }    
    stack < pair < int,int > > st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top().first >= v[i]){
            st.pop();
        }
        if(!st.empty()){
            cout << st.top().second << " ";
        }
        else{
            cout << 0 << " ";
        }
        st.push({v[i], i + 1});
    }
}
    </code></pre>
</details>  



# Queue
- FIFO (First in, first out)
- Insertion and Deletion happen on different ends
- Enqueue : Addition of element at the end of the queue
- Dequeue : Removal of element from front of the queue


```c++
queue <string> q;
q.push("ABC");
q.push("DEF");
q.push("GHI");
while(!q.empty()){
    cout << q.front << endl;    // ABC DEF GHI
    q.pop();
}
```



# Priority Queue