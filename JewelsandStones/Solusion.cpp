class Solution {
public:
    int findChar(char c, string S){
	  int count = 0;
	  for (int i = 0; i < S.length();i++)
	  {
		  if (S.at(i) == c)
		  {
			  count++;
		  }
	  }
	return count;
  }


    
    int numJewelsInStones(string J, string S) {
        int count = 0;
	      for (int i = 0; i < J.length(); i++)
	      {
	  	    count += findChar(J.at(i), S);
	      }
        return count;
    }
};
