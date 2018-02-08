class Solution {
public:
    string reverseVowels(string s) {
        string rst = s;
        string vowels = "aeiouAEIOU";
        vector<int> index;
        for(int i = 0;i<s.length();i++){
            if(vowels.find(s[i])!=-1)
                index.push_back(i);
        }
        for(int i = 0;i<index.size();i++){
            rst[index[i]] = s[index[index.size()-1-i]];
            
        }
        return rst;
    }
};
