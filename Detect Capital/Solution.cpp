class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word[0] >= 'a'){
            for(int i = 0;i<word.length();i++){
                if(word[i] <='Z')
                    return false;
            }
            
        }
        else{//大写
            if(word.length() == 1)
                return true;
            else if(word[1] < 'a'){//大写
                 for(int i = 1;i<word.length();i++){
                    if(word[i] > 'Z')
                    return false;
                }
            }
            else{
                     for(int i = 1;i<word.length();i++){
                        if(word[i] <= 'Z')
                        return false;
                    }
                }
            }
            
            

        return true;
    }
};
