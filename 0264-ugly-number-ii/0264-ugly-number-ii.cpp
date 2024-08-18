class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> s;
        if (n==1) return 1;
        long uglynum = 1;
        s.insert(uglynum);
        for(int i=0; i<n; i++){
            uglynum = *s.begin();
            s.insert(uglynum*2);
            s.insert(uglynum*3);
            s.insert(uglynum*5);
            s.erase(uglynum);
        }
        return uglynum;

    }
};