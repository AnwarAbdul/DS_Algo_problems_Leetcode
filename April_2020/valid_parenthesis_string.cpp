/*
Valid Parenthesis String
Solution
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
*/
class Solution {
public:
    bool checkValidString(string s) {
        vector<int> leftp_stack;
        vector<int> star_stack;
        int i;
        int flag = 1;
        for(i = 0; i < s.size(); i++){
            if(s[i] == '(')
                leftp_stack.push_back(i);
            else if(s[i] == '*')
                star_stack.push_back(i);
            else{
                if(leftp_stack.size() == 0){
                    if(star_stack.size())
                            star_stack.pop_back();     
                    else{
                        flag = 0;
                        break;
                    }
                }
                 else
                    leftp_stack.pop_back();
            }
        }
        
        if(flag == 0)
            return false;
        else{
            while(leftp_stack.size() > 0 && star_stack.size() > 0){
                if(star_stack.back() > leftp_stack.back()){
                    star_stack.pop_back();
                    leftp_stack.pop_back();
                }
                 else
                    return false;
            }
            if(leftp_stack.size() == 0)
                return true;
            else
                return false;
        }
    }
};