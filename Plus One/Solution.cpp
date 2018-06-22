class Solution {
public:
vector<int> plusOne(vector<int>& digits, int length){
	if (length == 0){
		vector<int> r;
		r.push_back(1);
		return r;
	}
	if (digits[length - 1] != 9){
		digits[length - 1]++;
		while (digits.size() != length)
			digits.pop_back();
		return digits;
	}
	else{
		digits[length - 1] = 0;
		vector<int> lead = plusOne(digits, length - 1);
		vector<int> r;
		for (int i = 0; i < lead.size(); i++){
			r.push_back(lead[i]);
		}
		r.push_back(0);
		return r;
	}

}


vector<int> plusOne(vector<int>& digits) {
	return plusOne(digits, digits.size());
}


};
