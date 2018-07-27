
class Solution {
public:
    bool isP(string s){
        for(int i = 0;i < s.length() / 2;i++){
            if(s[i] != s[s.length() - i-1])
                return false;
        }
        return true;
        
    }
    
    
    string longestPalindrome(string s) {
        if (s.length() == 0 || s.length() == 1){
            return s;
        }
        //cout << s.substr(1, 1);
        string rst;
        int start = 0;
        int maxlength = 1;
        for (int i = 0; i<s.length(); i++){
            //cout << i << endl;
            for (int j = maxlength; i+j <= s.length(); j++){
                //cout << "1" << i << " " << j << s.substr(i, j) <<   " "<< isP(s.substr(i, j)) << endl;

                if (isP(s.substr(i, j))){
                        start = i;
                        maxlength = j;
                }

            }

        }
        return s.substr(start, maxlength);
    }
};
