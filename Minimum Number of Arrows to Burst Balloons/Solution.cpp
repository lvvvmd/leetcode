
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end(), cmp);
        long long  i = 0, count = 0, start = INT_MIN, end = LLONG_MIN;
        while(i < points.size()){
            if(points[i].first > end){
                end = points[i].second;
                count++;
                i++;
            }
            else {
                end = points[i].second < end ? points[i].second : end;
                i++;
            }
            
        }
        return count;
    }
};
