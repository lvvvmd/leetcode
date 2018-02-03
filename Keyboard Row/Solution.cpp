class Solution {
public:
    bool find(string s, string key){
        for(int i = 0;i<s.length();i++){
            if(key.find(s[i]) == -1 && key.find(s[i] + 32) == -1)
                return false;
            
        }
        return true;
        
    }
    
    bool test(string s){
        vector<string> key = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        for(int i = 0;i<3;i++){
            if(find(s, key[i]))
                return true;
        }
        return false;
        
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> rst;
        
        
        for(int i = 0 ; i < words.size();i++){
            if(test(words[i]))
                rst.push_back(words[i]);
            
        }
        return rst;
    }
};
