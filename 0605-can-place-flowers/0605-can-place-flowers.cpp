class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int canplant = 0 , prev = -2, pres = 0, i=0;
        for(i = 0; i< flowerbed.size(); i++){
            if(flowerbed[i] == 1){
                canplant += (i - prev - 2)/2; 
                prev = i;
            }
        }
        ++i;
        canplant += (i - prev - 2)/2;
        return (n <= canplant);
    }
};