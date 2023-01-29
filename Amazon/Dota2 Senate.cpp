class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> qr, qd;
        for (int i = 0; i < n; ++i)
            senate[i] == 'R' ? qr.push(i) : qd.push(i);
        
        while (!qr.empty() && !qd.empty()) {
            if (qr.front() < qd.front()) {
                qr.push(qr.front() + n);
                qr.pop();
                qd.pop();
            }
            else {
                qd.push(qd.front() + n);
                qd.pop();
                qr.pop();
            }
        }
        
        return qr.empty() ? "Dire" : "Radiant";
    }
};
