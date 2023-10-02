class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        int cntA=0;
        int cntB=0;
        for(int i=1;i<n-1;i++){
            if(colors[i-1]=='A' && colors[i]=='A' && colors[i+1]=='A'){
                cntA++;
            }
            if(colors[i-1]=='B' && colors[i]=='B' && colors[i+1]=='B'){
                cntB++;
            }
        }
        return cntA>cntB;
    }
};