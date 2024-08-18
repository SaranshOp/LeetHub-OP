class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long> uglynumber(n);

        long index2=0, index3=0, index5=0;
        long index2v,index3v,index5v;

        uglynumber[0]=1;
        for(int i=1;i<n;i++){

            index2v = uglynumber[index2]*2;
            index3v = uglynumber[index3]*3;
            index5v = uglynumber[index5]*5;
            long mini = min({index2v,index3v,index5v});
            if(mini == index2v){
                uglynumber[i]= mini;
                index2++;
            }
            if(mini == index3v){
                uglynumber[i]= mini;
                index3++;
            }
            if(mini == index5v){
                uglynumber[i]= mini;
                index5++;
            }

        }
        return uglynumber[n-1];

    }
};