class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1)
            return 0;
        else if(K%2 == 0)
            return 1-kthGrammar(N-1, (K+1) / 2);
        else if(K%2 == 1)
            return kthGrammar(N-1, (K+1) / 2);
        
    }
};
