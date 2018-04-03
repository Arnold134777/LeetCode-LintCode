//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> _stack;
    stack<int> _minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        _stack = stack<int>();
        _minStack = stack<int>();
    }
    
    void push(int x) {
        if(_stack.empty()){
            _minStack.push(x);
        }else{
            _minStack.push(x < _minStack.top() ? x : _minStack.top());
        }
        _stack.push(x);
    }
    
    void pop() {
        if(_stack.empty()){
            return;
        }
        _minStack.pop();
        _stack.pop();
    }
    
    int top() {
        if(_stack.empty()){
            return -1;
        }
        return _stack.top();
    }
    
    int getMin() {
        if(_minStack.empty()){
            return -1;
        }
        return _minStack.top();
    }
};

int main(int argc, const char * argv[]) {

//    MinStack solution = MinStack();
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin() << endl;
    minStack.pop();
    std::cout << minStack.top() << endl;
    minStack.top();
    std::cout << minStack.getMin() << endl;
    minStack.getMin();
    return 0;
}


