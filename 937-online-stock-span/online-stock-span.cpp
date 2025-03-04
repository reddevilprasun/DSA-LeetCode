class StockSpanner {
public:
    stack<pair<int,int>>stack; //pair (prize,span)
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!stack.empty() && stack.top().first <= price){
            span += stack.top().second;
            stack.pop();
        }
        stack.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */