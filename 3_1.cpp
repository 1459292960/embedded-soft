#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string reverseParentheses(string s) 
    {
        stack<string> stk;
        string word = "";
        for (char c: s)
        {
            if (c == '(')           //遇到左括号  就是一个新的台阶了
            {
                stk.push(word);     //当前的这一段作为一个整体，存进stack
                word = "";          //重新计新的一段
            }
            else if (c == ')')      //当前这一段  要翻转  与前面的一段接起来
            {
                reverse(word.begin(), word.end());
                word = stk.top() + word;
                stk.pop();          //前面这一段不要了
            }
            else
                word += c;          //统计进当前这一段
        }
        return word;
    }


    int main(){
        string s;
        cin >>s;
        s = reverseParentheses(s);
        cout << s<<endl;
        return 0;
    }