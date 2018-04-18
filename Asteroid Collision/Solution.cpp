class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.size() == 0){
            return asteroids;
        }
        else{
            bool flag = false;
            for(int i = 0;i < asteroids.size() - 1;i++){
                if(asteroids[i] > 0 && asteroids[i+1] < 0){
                   if(abs(asteroids[i]) == abs(asteroids[i+1])){
                      asteroids.erase(asteroids.begin() + i);
                        asteroids.erase(asteroids.begin() + i);
                       i--;
                   } 
                    else if(abs(asteroids[i]) > abs(asteroids[i+1])){
                         asteroids.erase(asteroids.begin() + i+1);
                    }
                    else if(abs(asteroids[i]) < abs(asteroids[i+1])){
                        asteroids.erase(asteroids.begin() + i);
                    }
                    i--;
                    flag = 1;
                }
            }
            if(flag){
                return asteroidCollision(asteroids);
            }
            else
                return asteroids;
            
            
            
        }
    }
};
