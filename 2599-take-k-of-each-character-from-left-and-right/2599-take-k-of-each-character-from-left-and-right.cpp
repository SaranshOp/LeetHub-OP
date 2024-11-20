class Solution {
public:
    int takeCharacters(string s, int k) {
        //cout << "s" << s << endl;
        int n = s.size();
        cout << "n" << n << endl;
        int i = 0, j = 0, maxi = 0;
        vector<int> count(3, 0);
        for (auto k : s) {
            count[k - 'a']++;
        }
        if (!valid(count, k))
            return -1;

        cout << "count " << count[0] << " " << count[1] << " " << count[2]
             << endl;
        while (j < n) {
            //cout << "j" << j << endl;
            int ele = s[j];
            count[ele - 'a']--;
            if (valid(count, k)) {
                maxi = max(maxi, j - i + 1);
                cout << "maxi " << maxi << endl;
            }
            while (i <= j && !valid(count, k)) {
                cout << "i" << i << endl;
                int ele2 = s[i];
                count[ele2 - 'a']++;
                i++;
            }
            j++;
        }
        return n - maxi;
    }

private:
    bool valid(vector<int> count, int k) {
        return !(count[0] < k || count[1] < k || count[2] < k);
    }
};