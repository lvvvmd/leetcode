class Solution {
public:
    
vector<int> constructArray(int n, int k) {
	vector<int> rst;
	for(int i = 0;i<k+1;i++){
        rst.push_back(i%2==0?(i/2+1):(k+1-(i-1)/2));
    }
    for(int i = k+2;i<n+1;i++){
        rst.push_back(i);
    }
	return rst;
}
};
