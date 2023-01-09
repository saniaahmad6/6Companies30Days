class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector <int> time,amount;
        vector <string> name,place;
        vector <string> ans;
        int n=transactions.size();
        for (auto &i: transactions){
            string s=i;
            int pos = s.find(',');
            name.emplace_back(s.substr(0,pos+1));
            s=s.substr(pos+1,s.size());

            pos = s.find(',');
            time.emplace_back(stoi(s.substr(0,pos+1)));
            s=s.substr(pos+1,s.size());

            pos = s.find(',');
            amount.emplace_back(stoi(s.substr(0,pos+1)));
            s=s.substr(pos+1,s.size());

            place.emplace_back(s.substr(0,s.size()));
        }

        for (int i=0;i<n;i++){
            bool f=0;
            //amount exceeds 1000
            if (amount[i]>1000){
                f=1;
                
            }
            
            for (int j=0 ;j<n;j++){
                if (i==j) continue;
                if (name[i]==name[j] && place[i]!=place[j] && abs(time[i]-time[j])<=60){
                        f=1;
                        break;
                }
            }
            if (f) ans.emplace_back(transactions[i]);
        }
        return ans;
    }
};
