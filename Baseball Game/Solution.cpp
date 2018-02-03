class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> roundsScore;
        int sum = 0;
        for(int i = 0;i<ops.size();i++){
            switch(ops[i][0]){
                case 'D':{
                    roundsScore.push_back(roundsScore.back() * 2);
                    sum += roundsScore.back();
                    break;
                }        
                case 'C':{
                    sum -= roundsScore.back();
                    roundsScore.pop_back();
                    break;
                }    
                case '+':{
                    int tmp = 0;
                    tmp += *(roundsScore.end()-1);
                    tmp += *(roundsScore.end()-2);
                    roundsScore.push_back(tmp);
                    sum += tmp;
                    break;
                }
                default:
                    {
                        int a = atoi(ops[i].c_str());
                        roundsScore.push_back(a);
                        sum+=a;
                        break;
                    }
            }
        }
     return sum;   
    }
};
