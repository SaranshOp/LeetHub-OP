class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=1; i<n; i++){
            auto &v = triangle[i-1];
            int ni= triangle[i].size();
            int mini;
            for(int j = 0; j<ni ; j++ ){
                if(j==0) mini = v[j];
                else if(j==ni-1) mini = v[j-1]; 
                else mini = min(v[j],v[j-1]);
                triangle[i][j] += mini;
            }
        }
        return *min_element(triangle.back().begin(),triangle.back().end());
    }
};