class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        string s="";
        int carry=0;
        while(i >= 0 || j >= 0){
            int temp = carry;
            if(i >= 0) temp += a[i] - '0';
            i--;
            if(j >= 0) temp += b[j] - '0';
            j--;
            
            if(temp > 1) carry = 1;
            else carry = 0;
            
            s += to_string(temp%2);
        }
        if(carry > 0) s += to_string(carry);
    
        reverse(s.begin(), s.end());
        return s;
    }
};