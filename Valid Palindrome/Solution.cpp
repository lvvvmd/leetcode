class Solution {
public:
    bool isPalindrome(string s) {
        string ns;
        for(int i = 0;i<s.length();i++){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9'){
                ns += s[i];
            }
            else if(s[i] >= 'A' && s[i] <= 'Z')
                {
                ns += s[i] - 'A' + 'a';
            }
        }
        if(ns.length() <= 1)
            return true;
        
        for(int i = 0;i < ns.length()/2+1;i++){
            if(ns[i] != ns[ns.length()-1-i])
                return false;
        }
            
        
        return true;
        
    }
};
