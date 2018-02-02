class Solution {
public:
    string reverseWords(string s) {
        string rst;
        int space, lastspace = 0;
        while((space = s.find(' ', lastspace)) != -1){
            reverse(s.begin() + lastspace, s.begin() + space);
            lastspace = space +1;
        }
        reverse(s.begin() + lastspace, s.end());
        return s;
    }
};
