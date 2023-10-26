class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        const int mod = 1e9+7;
        int n = arr.size();
        vector<int> dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            int curr = arr[i];
            int val = 1;
            for(int j=0;j<i;j++)
            {
                if(curr%arr[j]==0)
                {
                    int temp = curr/arr[j];
                    if(temp>arr[j])
                    {
                        int l = j+1;
                        int r = i;
                        while(l<r)
                        {
                            int m = l+(r-l)/2;
                            if(arr[m]>=temp){r=m;}
                            else{l=m+1;}
                        }
                        if(arr[l]==temp)
                        {
                            long long r1 = dp[j];
                            long long r2 = dp[l];
                            val=(val+(2*r1*r2)%mod)%mod;
                        }
                    }
                    else if(temp==arr[j])
                    {
                        long long req = dp[j];
                        val=(val+(req*req)%mod)%mod;
                        break;
                    }
                    else{break;}
                }
            }
            dp[i]=val;
        }   
        int ans = 0;
        for(int x: dp){ans=(ans+x)%mod;}
        return ans;
    }
};