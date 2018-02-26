class Solution {
public:
    int compare(string s1, string s2){
        int s1count = 0, s2count = 0;
        for(int i = 0;i<s1.length();i++){
            s1count |= 1 << (s1[i] - 'a');
        }
        for(int i = 0;i<s2.length();i++){
            s2count |= 1 << (s2[i] - 'a');
        }
       // cout << s1 << " " <<s2 << "  "<<(s1count & s2count) << endl;
        if((s1count & s2count) != 0)
            return 0;
        else{
            return s1.length() * s2.length();    
        }
    }
    int maxProduct(vector<string>& words) {
        if(words.size() <= 1)
            return 0;
        else{
            int rst = 0;
            for(int i = 0;i<words.size() -1;i++){
                for(int j = i+1;j<words.size();j++){
                int tmp = compare(words[i], words[j]);
                rst = rst > tmp? rst : tmp;
                }
                //cout << "rst = " << rst << endl;
            }
            //words.erase(words.begin());
            //int tmp = maxProduct(words);
            //rst = rst > tmp?rst:tmp;
            //cout << "rst = " << rst << endl;
            return rst;
        }
    }
};
