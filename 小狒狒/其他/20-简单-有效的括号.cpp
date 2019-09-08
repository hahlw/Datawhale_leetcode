class Solution {
public:
    bool isValid(string s) {
        if(s == " ") return true;
        if(s.size() % 2 != 0) return false;
        stack<char> symbols;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                symbols.push(s[i]);
            else{
                if(symbols.size() == 0)
                    return false;
                char match;
                if(s[i] == ')')
                    match = '(';
                else if(s[i] == ']')
                    match = '[';
                else if(s[i] == '}')
                    match = '{';
                char c = symbols.top();
                symbols.pop();
                
                if( c != match )
                    return false;
            }
        }
        if(symbols.size() != 0) return false;
        return true;
    }
};
