class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> rst;
        for(int i = 1;i<=n;i++){
            
            int a = i%3;
            int b = i%5;
            if(a == 0 && b==0){
                rst.push_back("FizzBuzz");
            }
            else if(a==0){
                rst.push_back("Fizz");
            }
            else if(b == 0)
                rst.push_back("Buzz");
            else
                rst.push_back(to_string(i));
            
            
        }
     return rst;   
    }
};
