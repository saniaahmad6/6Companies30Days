//Leetcode 2212
class Solution {
public:
    vector <int> v;
    int ans=0;
    void help (int index,int stock,vector<int>& alice,int currsum,vector <int> bob){
        if (index==12 || stock<=0){
            //reached end
            if (currsum > ans){
                if (stock>0){
                bob[11] +=stock;
                
            }
                ans=currsum; v=bob;
            }
            
            return;
        }
        
        //pick
        int req=alice[index]+1;
        if (req<=stock){
            bob[index]=req;
            help(index+1,stock-req,alice,currsum+index,bob);
            bob[index]=0;
        }
        //notpick
        help (index+1,stock,alice,currsum,bob);

    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector <int> bob(12,0);
        help(0,numArrows,aliceArrows,0,bob);
        return v;

    }
};
