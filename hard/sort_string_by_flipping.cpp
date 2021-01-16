/*
  Sort String by Flipping
  Question 173 of 1002
  
  https://binarysearch.com/problems/Sort-String-by-Flipping
*/

int solve(string s) {
    int n = s.length(); 
    vector<int> flipsFromLeft(n); 
    vector<int> flipsFromRight(n); 
  
    int flips = 0;  
    for (int i = 0; i < n; i++) { 
        if (s[i] == 'y')  
            flips++;          
        flipsFromLeft[i] = flips;  
    } 
    
    flips = 0; 
    for (int i = n - 1; i >= 0; i--) { 
        if (s[i] == 'x')  
            flips++;          
        flipsFromRight[i] = flips;  
    } 

    int minFlips = n > 0 ? min(flipsFromLeft[n-1], flipsFromRight[0]) : 0;  
    for (int i = 1; i < n; i++) { 
        if (flipsFromLeft[i - 1] + flipsFromRight[i] < minFlips) 
            minFlips = flipsFromLeft[i - 1] + flipsFromRight[i]; 
    } 

    return minFlips; 
}
