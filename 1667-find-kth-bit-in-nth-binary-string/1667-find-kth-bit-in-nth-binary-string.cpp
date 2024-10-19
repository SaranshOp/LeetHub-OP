class Solution {
public:
    char findKthBit(int n, int k) {
        // n = 4 k = 11
        if(n==1) return '0';
        int len  =  (1 << n) - 1;
        int mid = len / 2 + 1;

        if(k == mid) return '1';
        if(k < mid) return findKthBit(n-1,k);
        else{
            return findKthBit(n-1, len - k+1) =='1' ? '0':'1';
        } 

    }
};

// string inverse(S) {
//     for () {
//         S[i] = S[i] ^ 1;
//     }
//     return S;
// }
// char findKthBit(int n, int k) {
//     for (i < n) {
//         invS = inverse(S);
//         S += "1" + invS;
//     }
//     return S[k];
// }