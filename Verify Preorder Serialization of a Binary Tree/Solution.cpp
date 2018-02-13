class Solution {
public:
    bool isValidSerialization(string preorder) {
       // if(preorder.length()%2 == 0)
        //    return false;
        preorder = ","+preorder;
        int j = preorder.find(',');
        int tofill = 1;
        while(j!=-1){
            if(tofill == 0)
                return false;
            if(preorder[j+1] == '#')
                tofill--;
            else
                tofill++;
            
            j = preorder.find(',', j+1);
            
        }
        if(tofill != 0)
            return false;
        else
            return true;
    }
};
