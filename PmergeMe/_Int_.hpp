# ifndef INT__HPP
# define INT__HPP

class _Int_
{
    // 35 is sufficient depth for N up to 2^35. 
    // For production, a std::vector<int> would be safer but slower.
    private:
        int indx[64];   // use
        int c;  // use
    public:
        static int Count;   // just counter of the operations
        int value;
        _Int_ (int val = 0): value(val) { c = 0; }
    
        // Logic to track permutations through recursion
        int pop() {
            c--;
            return indx[c];
        }
        void push(int i) {
            indx[c] = i;
            c++;
        }
        bool operator<(const _Int_ &obj) const {
            Count++;
            return value < obj.value;
        }
};

# endif
