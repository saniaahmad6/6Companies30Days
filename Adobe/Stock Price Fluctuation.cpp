class StockPrice {
public:
    
    map <int,int> m;// time : price
    multiset <int> prices;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (m.find(timestamp)==m.end()){
            //not
            prices.insert(price);

        }
        else{// there so change prices set
            auto it =prices.find((m.find(timestamp))->second);
            prices.erase(it);
            prices.insert(price);
        }
        m[timestamp] = price; 
        
    }
    
    int current() {
        auto it=m.end();
        it--;
        return it->second;
    }
    
    int maximum() {
        auto it=prices.end();
        it--;
        return *it;

    }
    
    int minimum() {
        auto it=prices.begin();
        return *it;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
