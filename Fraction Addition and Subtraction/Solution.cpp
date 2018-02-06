class Solution {
public:
    class Fraction{
	int fenzi;
	int fenmu;
public:
	Fraction(int fz, int fm){
		fenzi = fz;
		fenmu = fm;
	}
	int gcd(int a, int b) {
		int t;
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

	void Add(Fraction num){

		fenzi = fenzi*num.fenmu + fenmu*num.fenzi;
		fenmu *= num.fenmu;
        if (fenzi == 0){
			fenmu = 1;
			return;
		}
		int tmp = gcd(abs(fenzi), fenmu);
		fenzi /= tmp;
		fenmu /= tmp;
	}

	void Sub(Fraction num){
		Add(Fraction(num.fenzi * -1, num.fenmu));


	}

	double GetDouble(){
		return fenzi * 1.0 / fenmu;

	}
	string GetString(){
		
		return to_string(fenzi) + "/" + to_string(fenmu);


	}
};

Fraction FractionAddition2(string expression){
	cout << expression << endl;
	if (expression.length() == 0)
		return Fraction(0, 1);
	if (expression.find('-')!=-1){

		string left = expression.substr(0, expression.find('-'));
		//string right = "";
		for (int i = expression.find('-') + 1; i < expression.length(); i++){
			if (expression[i] == '-'){
				expression[i] = '+';
			}
			else if (expression[i] == '+')\
				expression[i] = '-';
		}
		string right = expression.substr(expression.find('-') + 1, expression.length());
		Fraction f1 = FractionAddition2(left);
		Fraction f2 = FractionAddition2(right);
		f1.Sub(f2);
		return f1;
	}
	else if (expression.find('+') != -1){
		Fraction f1 = FractionAddition2(expression.substr(0, expression.find('+')));
		Fraction f2 = FractionAddition2(expression.substr(expression.find('+') + 1, expression.length() + 1));
		f1.Add(f2);
		return f1;
	}
	else if (expression.find('/') != -1){
		return Fraction(atoi((expression.substr(0, expression.find('/'))).c_str()), atoi((expression.substr(expression.find('/') + 1, expression.length() + 1)).c_str()));

		//return FractionAddition2() / FractionAddition2();
	}
	//else
		//return expression[0] - '0';


}
    string fractionAddition(string expression) {
        Fraction rst = FractionAddition2(expression);
	//cout << rst.GetDouble() << endl;

	//cout << rst.GetString() << endl;

	return rst.GetString();
    }
};
