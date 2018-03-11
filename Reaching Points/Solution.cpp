class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (1){
		if (sx > tx || sy > ty)
			return false;
		else if (sx == tx)
            return (ty - sy) % tx == 0;
        else if(sy == ty)
                return (tx - sx) % sy == 0;
        else if(tx > ty)    
				tx -= ty;
		else
				ty -= tx;
	}
    }
};
