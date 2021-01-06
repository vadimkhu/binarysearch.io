/*
  Set Bits
  Question 68 of 1000

  https://binarysearch.com/problems/Set-Bits
*/

/*
https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/?ref=rp
Method 3 (Tricky)
If the input number is of the form 2^b -1 e.g., 1, 3, 7, 15.. etc, the number of set bits is b * 2^(b-1). This is because for all the numbers 0 to (2^b)-1, if you complement and flip the list you end up with the same list (half the bits are on, half off).
If the number does not have all set bits, then some position m is the position of leftmost set bit. The number of set bits in that position is n – (1 << m) + 1. The remaining set bits are in two parts:

1) The bits in the (m-1) positions down to the point where the leftmost bit becomes 0, and
2) The 2^(m-1) numbers below that point, which is the closed form above.

An easy way to look at it is to consider the number 6:

0|0 0
0|0 1
0|1 0
0|1 1
-|--
1|0 0
1|0 1
1|1 0
The leftmost set bit is in position 2 (positions are considered starting from 0). If we mask that off what remains is 2 (the “1 0” in the right part of the last row.) So the number of bits in the 2nd position (the lower left box) is 3 (that is, 2 + 1). The set bits from 0-3 (the upper right box above) is 2*2^(2-1) = 4. The box in the lower right is the remaining bits we haven’t yet counted, and is the number of set bits for all the numbers up to 2 (the value of the last entry in the lower right box) which can be figured recursively.
*/

unsigned int getLeftmostBit(int n) {  
    int m = 0;  
    while (n > 1) {  
        n = n >> 1;  
        m++;  
    }  
    return m;  
}  

unsigned int getNextLeftmostBit(int n, int m) {  
    unsigned int temp = 1 << m;  
    while (n < temp) {  
        temp = temp >> 1;  
        m--;  
    }  
    return m;  
}  

unsigned int _countSetBits(unsigned int n, int m);

unsigned int countSetBits(unsigned int n) {  
    int m = getLeftmostBit(n);    
    return _countSetBits(n, m);  
}  

unsigned int _countSetBits(unsigned int n, int m) {  
    if (n == 0)  
        return 0;  
  
    m = getNextLeftmostBit(n, m);  
    if (n == ((unsigned int)1 << (m + 1)) - 1)  
        return (unsigned int)(m + 1) * (1 << m);  
  
    n = n - (1 << m);  
    return (n + 1) + countSetBits(n) + m * (1 << (m - 1));  
}  

int solve(int n) {
    return countSetBits(n);     
}
