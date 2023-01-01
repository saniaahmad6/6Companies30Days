class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        unordered_map <char,int> h1,h2;
        int bulls=0,cows=0;
        for (int i=0;i<n;i++){
            if (secret[i]==guess[i]){
                bulls++;
            }
            else{
                if (h2[secret[i]]>=1){
                    cows++;
                    h2[secret[i]]--;
                }
                else{
                    h1[secret[i]]++;
                }
                if (h1[guess[i]]>=1){
                    cows++;
                    h1[guess[i]]--;
                }
                else{
                    h2[guess[i]]++;
                }
            }
        }
        string ans;
        string x=to_string(bulls),y=to_string(cows);
        ans+=x;
        ans+='A';
        ans+=y;
        ans+='B';
        return ans;
    }
};
