class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0.0){return 0.0;}
        if(n == 0){return 1.0;}
        if(n < 0){return 1.0/(x*myPow(x,-n-1));}
        return n%2 == 0? myPow(x*x,n/2): x*myPow(x*x,n/2); // time complexity O(log(n))
    }
};