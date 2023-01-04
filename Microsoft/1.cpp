/*
150. Evaluate Reverse Polish Notation


You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.
*/

// Leet Code Solution

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> art;
        for(auto i:tokens) {
            if(i=="+" or i=="-" or i=="*" or i=="/") {
                int x=stoi(art.top());
                art.pop();
                int y=stoi(art.top());
                art.pop();
                if(i=="+")
                    art.push(to_string(y+x));
                else if(i=="-")
                    art.push(to_string(y-x));
                else if(i=="*")
                    art.push(to_string(x*y));
                else if(i=="/")
                    art.push(to_string(y/x));
            }
            else
                art.push(i);
        }
        int ans=stoi(art.top());
        return ans;
    }
};