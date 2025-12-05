#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <iterator>

// test to see if the numebr is_sorted()
template <typename ForwardIterator>
bool isSorted(ForwardIterator first, ForwardIterator last) {
    if (first == last)
        return true;
    ForwardIterator next = first;
    ++next;
    while (next != last)
    {
        if (*next < *first)
            return false;
        // std::cout << "*it -> " << *first.value;
        ++first;
        ++next;
    }
    return true;
}

// --- Int Wrapper Class ---
// ----------------------------------------------------------------------------------------------
class Int 
{
    // 35 is sufficient depth for N up to 2^35. 
    // For production, a std::vector<int> would be safer but slower.
    private:
        int indx[64];   // use
        int c;  // use
    public:
        static int Count;   // TOKNOW static memebr of the calss is not a memeber of an object of Int class
        int value;
        Int (int val = 0): value(val) { c = 0; }
    
        // Logic to track permutations through recursion
        int pop() {
            c--;
            return indx[c];
        }
        void push(int i) {
            indx[c] = i;
            c++;
        }
        bool operator<(const Int &obj) const {
            Count++;
            return value < obj.value;
        }
};
// ----------------------------------------------------------------------------------------------

int Int::Count = 0;

void MISort(std::vector<Int> &nums)
{
    int n = nums.size();
    if (n < 2) return;

    std::vector<Int> a, b, rB;

    // 1. Pairwise comparison
    for(int i = 0; i < n - 1; i+=2)
    {
        if(nums[i] < nums[i + 1])
        {
            
            nums[i + 1].push(a.size());
            a.push_back(nums[i + 1]);
            b.push_back(nums[i]);
        }
        else
        {
            nums[i].push(a.size());
            a.push_back(nums[i]);
            b.push_back(nums[i + 1]);
        }
    }
    // Handle odd element
    if (n % 2) {
        b.push_back(nums[n - 1]);
    }

    // 2. Recursively sort the larger elements ('a')
    MISort(a);





    // ---------------------------------------------------------------------------------





    // 3. Reconstruct 'b' in the order corresponding to sorted 'a'
    // 'a' is now sorted. We use the indices stored in 'a' to find 
    // which element in 'b' was originally paired with it.
    n = a.size();
    for(int i = 0; i < n; i++)
    {
        int idx = a[i].pop();
        rB.push_back(b[idx]);
    }
    // If there was an odd element, it is at the end of b/rB
    if (b.size() > a.size()) {
        rB.push_back(b.back());
    }

    // 4. Merge Phase (Ford-Johnson Insertion)
    nums.clear();
    
    // The first element of rB (b_0) is always the smallest of the paired set, 
    // and smaller than a_0.
    nums.push_back(rB[0]); 
    
    int u = 0; // Index for 'a' elements added to 'nums'
    int n_b = rB.size(); // Size of pendant chain
    int k = 2; // Jacobsthal index
    int tk_ = 0; // Previous Jacobsthal number
    
    // We process b starting from index 1 (since rB[0] is done)
    // Note: In standard FJ, we treat rB elements 1..n
    
    while(u < (int)a.size())
    {
        // Calculate next Jacobsthal number
        // J_k = (2^(k+1) + (-1)^k) / 3
        int tk = ((pow(2, k + 1) + pow(-1, k)) / 3) - 1;
        
        // The block end in 'b' we are processing
        int m = std::min(tk, n_b - 1); // -1 because rB is 0-indexed

        // FIX 2: Add 'a' elements to Main Chain BEFORE inserting 'b'
        // We must ensure a[i] is in 'nums' before we try to insert b[i],
        // because a[i] acts as the upper bound for b[i].
        // We add 'a' elements up to index 'm'.
        while(u <= m && u < (int)a.size()) {
            nums.push_back(a[u++]);
        }

        // Now insert b elements from m down to tk_ + 1
        // We skip index 0 because it was handled at start.
        for (int i = m; i > tk_; i--)
        {
            // Edge case: if i matches the odd element out (no pair in a)
            // we search the whole list. Otherwise, we search up to its pair.
            // But since 'nums' is growing, searching .end() is easiest and valid O(log N).
            
            // Optimization: We could limit the search range, but .end() is safe.
            std::vector<Int>::iterator it = std::lower_bound(nums.begin(), nums.end(), rB[i]);
            nums.insert(it, rB[i]);
        }

        tk_ = tk;
        k++;
        
        // Break if we have processed all 'a's and 'b's
        if (tk_ >= n_b && u >= (int)a.size()) break;
    }
    
    // If any 'a' elements remain (rare, but possible with odd sizes/math rounding)
    while(u < (int)a.size()) {
        nums.push_back(a[u++]);
    }
    // If any 'b' elements remain (the odd one out at the very end)
    while (tk_ + 1 < n_b) {
        tk_++;
         std::vector<Int>::iterator it = std::lower_bound(nums.begin(), nums.end(), rB[tk_]);
         nums.insert(it, rB[tk_]);
    }
}

int main()
{
    std::srand(std::time(0));
    
    std::vector<Int> nums;

    // Test with 3000 random elements
    for (int i = 0; i < 21; ++i)
    {
        int value = std::rand();
        nums.push_back(value);
    }

    // std::cout << "Sorting " << nums.size() << " elements..." << std::endl;

    struct timeval tv, tv2;
    gettimeofday(&tv, NULL);
    
    MISort(nums);

    
    gettimeofday(&tv2, NULL);
    long time_us = ((long)tv2.tv_sec * 1000000 + tv2.tv_usec) - ((long)tv.tv_sec * 1000000 + tv.tv_usec);

    std::cout << "Number of Comparisons: "<< Int::Count ;
    std::string s = isSorted(nums.begin(), nums.end()) ? "true" : "false";
    std::cout << "\n" <<"isSorted: " << s << "\nTime: " << time_us / 1000.0 << " ms\n";

    return 0;
}