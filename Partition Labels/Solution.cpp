class Solution {
public:
    bool IsIn(string S, char c, int start, int end){
        
        for(int i = start; i < end; i++){
            if(S[i] == c)
            return 1;
        }
        return 0;
        
        
    }
    int ReverseFind(string S, char c){
        for(int i = S.length()-1;i>=0;i--){
            if(c == S[i])
                return i;
            
        }
        
    }
    
    vector<int> partitionLabels(string S) {
        
        int start = 0, end = 1;
        vector<int> rst;
        while(start < S.length()){
            int count = 1, last;
            end = ReverseFind(S, S[start]); // 找到最后一个出现的位置
            for(last = end+1;last < S.length();last ++){
                if(IsIn(S, S[last], start, end))
                    end = last;
            }
            rst.push_back(end - start +1);
            
            end = end + 1;
            start = end;
            
        }
        
        return rst;
    }
};
