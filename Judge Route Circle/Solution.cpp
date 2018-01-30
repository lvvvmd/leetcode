class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(int i = 0; i < moves.length();i++){
            switch(moves.at(i)){
                case 'R':{
                    x++;
                    break;
                }
                case 'L':{
                    x--;
                    break;
                }
                case 'U':{
                    y++;
                    break;
                }
                case 'D':{
                    y--;
                    break;
                }
                default:{
                    break;
                }
            }
            
            
        }
        if(x == 0 && y==0)
            return 1;
        else
            return 0;
        
    }
};
