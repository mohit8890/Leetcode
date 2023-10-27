class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        vector<int>num(num1.size()+num2.size(),0);
        for(int i=num1.size()-1;i>=0;i--){
            for(int j=num2.size()-1;j>=0;j--){
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                num[i + j] += num[i + j + 1] / 10;
                num[i + j + 1] %= 10;
            }
        }
        // skipping leading zeroes
        int i=0;
        while(num[i]==0 && i<num.size()){
            i++;
        }
        // converting into string
        string ans="";
        for(;i<num.size();i++){
           ans.push_back(num[i]+'0');
        }
        return ans;
        
        
    }
};