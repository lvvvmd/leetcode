class Solution {
public:
    int findLUSlength(string a, string b) {
        return a==b?-1:(a.length() > b.length()?a.length():b.length());
    }
};
