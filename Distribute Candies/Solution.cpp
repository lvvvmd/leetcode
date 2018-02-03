class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int length = candies.size();
        sort(candies.begin(),candies.end());
        candies.erase(unique(candies.begin(), candies.end()), candies.end());
        int length2 = candies.size();
        return length/2 > length2 ? length2:length/2;
        
    }
};
