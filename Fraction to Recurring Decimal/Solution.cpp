class Solution {
public:
    
long long gcd(long long  a, long long b) {
	long long t;
	if (a < b) {
		t = a;
		a = b;
		b = t;
	}
	while (t = a % b) {
		a = b;
		b = t;
	}
	return b;
}

    string fractionToDecimal(long long numerator, long long denominator) {

    string rst = "";
	if (numerator*denominator < 0)
		rst += "-";

	numerator = abs(numerator);
	denominator = abs(denominator);

	long long zhengshubufen = numerator / denominator;
	numerator -= zhengshubufen * denominator;
	if (numerator == 0)
		return rst + to_string(zhengshubufen);

	long long gcdnum = gcd(numerator, denominator);
	numerator /= gcdnum;
	denominator /= gcdnum;
	 rst += to_string(zhengshubufen) + ".";
	 long long tmpdn = denominator;
	while (tmpdn % 2 == 0 || tmpdn % 5 == 0){
		if (tmpdn % 2 == 0)
			tmpdn /= 2;
		if (tmpdn % 5 == 0)
			tmpdn /= 5;
	}


	if (tmpdn == 1){
		//不循环
		while (numerator != 0){
			numerator *= 10;
			long long mul = numerator / denominator;
			rst += to_string(mul);
			numerator -= denominator * mul;
		}
		
	}
	else{
		//循环
		//rst += "(";
		//bool first = true;
		long long orinum = numerator;
		vector<long long> remainder, quotient;
		//remainder.push_back(numerator);
		while (find(remainder.begin(), remainder.end(), numerator) == remainder.end()){
			remainder.push_back(numerator);
			
			numerator *= 10;
			long long mul = numerator / denominator;

			quotient.push_back(mul);
			numerator -= denominator * mul;
		}

		auto i = find(remainder.begin(), remainder.end(), numerator);
		long long j = 0;
		for (; j < i - remainder.begin(); j++){
			rst += to_string(quotient[j]);
		}
		rst += "(";
		for (; j < quotient.size(); j++){
			rst += to_string(quotient[j]);
		}

		rst += ")";
		
	}
	return rst;
    }
};
