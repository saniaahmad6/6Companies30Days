class Solution {
public:
    string fractionToDecimal(int numer, int deno) {
        long long numerator = numer;
        long long denominator = deno;
        if (numerator % denominator == 0) return to_string(numerator / denominator);
        int f=0;
        if (numerator>0 && denominator <0){
            f=1;
        }
        else if (numerator<0 && denominator >0){
            f=1;
        }
       
        
        numerator =abs(numerator);
        denominator = abs(denominator);
         string ans = to_string(numerator / denominator);
        long long num = (numerator % denominator) * 10; // 1->10
        ans+=".";
        map <pair<int,int>,int> m;
        while (1){
            cout<<num<<" ";
            int q = num/denominator;
            long long rem=num%denominator;
            
            cout<<rem<<endl;
            
             
            num = (rem) * 10;
            if (m.find({rem,q})==m.end()){
                m[{rem,q}]=ans.size();
            }
            else {
                int pos =m[{rem,q}];
                ans = ans.insert(pos,1,'(');
                ans+=')';
                break;
            
            }
            ans += to_string(q);
            if (rem == 0) break;
        }
        if (f) ans = ans.insert(0,1,'-');
        return ans;
    }
};
