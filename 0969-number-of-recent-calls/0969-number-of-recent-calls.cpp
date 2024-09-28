#include <vector>

class RecentCounter {
public:
    RecentCounter() {
        counter.clear();
    }

    int ping(int t) {
        counter.push_back(t);

        if (counter.size()) {
            int count = 0;
            for (int s : counter) {
                if (s >= t - 3000) {
                    //ṇcout << s << endl;
                    count++;
                }
            }
            return count;
        } else {
            return counter.size();
        }
    }

private:
    std::vector<int> counter;
};