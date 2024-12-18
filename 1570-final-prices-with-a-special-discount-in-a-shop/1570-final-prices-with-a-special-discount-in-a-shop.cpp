class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        for(int i= prices.size()-1; i>=0; i--){
            int ele = prices[i];
            int ins = ele;
            while(!stk.empty() && stk.top() > ele ){
                stk.pop();
            }
            if(!stk.empty()) ins = ele - stk.top();
            stk.push(ele);
            prices[i] = ins;
        }
        return prices;
    }
};