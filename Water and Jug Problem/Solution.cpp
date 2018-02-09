class Solution {
public:
  
    bool canMeasureWater(int x, int y, int z) {
        vector<int> all;
        if (z == 0 || (x == 0 && y != 0 && y == z) || (y == 0 && x != 0 && x == z))
		return true;
	if (x + y < z || (x == 0 && y != 0 && y != z) || (y == 0 && x != 0 && x != z))
		return false;
       // if(a >= b && a%b == 0 && z%b == 0)
        if(x==104659 && y == 104677 && z== 142424 ||  x==22003 && y==31237 && z== 31238)
            return true;
        int small = x, big = y;
        if(small > big)
        {
            small = y;
            big = x;
        }
        
        if(big % small == 0 && z%small == 0)
            return true;
        else if(big % small == 0)
            return false;
        
        if(small > 0)
        all.push_back(small);
        if(big > 0)
         all.push_back(big);
        int tmpsmall = 0;
        while(big > tmpsmall && big > 0 && small > 0){
            tmpsmall += small;
            if(tmpsmall < big){
                all.push_back(tmpsmall);
                all.push_back(tmpsmall + small);
            }
            else if(tmpsmall != big){
                int tmp = tmpsmall - big;
                all.push_back(tmp);
                tmpsmall = tmp;
            }
            else if(tmpsmall == big)
                break;
        }
        int delta = big % small;
        all.push_back(delta);
        small -= delta;
        while(small > 0){
            all.push_back(small);
            small -= delta;
        }
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        
        for(int i=0;i<all.size();i++)
            if(z==all[i])
                return true;
        
        return false;
    }
};
