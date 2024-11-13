class Solution
{
public:
    bool primeSubOperation(vector<int> &nums)
    {
        // Generate a list of prime numbers up to 1000
        vector<int> primes;
        sieve(primes, 1000); // Helper function to fill the primes vector

        for (int i = 0; i < nums.size(); i++)
        {
            // Find the largest prime number less than or equal to nums[i]
            int j = lower_bound(primes.begin(), primes.end(), nums[i]) - primes.begin() - 1;
            if(j==-1) continue;
            cout << "i: " << i << " " ;
            cout << "nums[i]: " << nums[i] << " ";
            cout << "j: " << j << " ";
            cout << "primes[j]: " << primes[j] << " ";
            cout << endl;
            // Adjust the first element directly
            if (i == 0)
            {
                nums[i] -= primes[j]; // Subtract the largest prime from the first element
                cout << " Fnums[i]:s " << nums[i] << endl;  
                continue;
            } // initial j
            // Find a suitable prime such that nums[i] - primes[j] is less than nums[i-1]
            while (j>=0 && nums[i - 1] >= nums[i] - primes[j])
            {
                j--; // Move to the next smaller prime
            }
            if(j<0 && nums[i-1] < nums[i]) continue;
            cout << " HERE!Outside " << endl;
            // If no valid prime can be subtracted, return false
            if (j < 0 || nums[i] <= primes[j]){
                cout << " HERE!Inside ";
                return false;
            }

            // Subtract the valid prime from the current element
            nums[i] -= primes[j];

            cout << " Fnums[i]: " << nums[i] << endl;  
        }

        // Check if the resulting array is sorted in ascending order
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= nums[i - 1]){
                cout<<"false here";
                return false;
                }
        }

        return true; // All operations were successful and the array is sorted
    }
private:
    void sieve(vector<int> &primes, int n)
    {
        // Sieve of Eratosthenes to generate all prime numbers up to n
        vector<bool> isPrime(n + 1, true);
        for (int p = 2; p * p <= n; p++)
        {
            if (isPrime[p])
            {
                for (int i = p * p; i <= n; i += p)
                {
                    isPrime[i] = false;
                }
            }
        }
       // primes.push_back(1);
        for (int p = 2; p <= n; p++)
        {
            if (isPrime[p])
                primes.push_back(p); // Add prime numbers to the list
        }
    }
};