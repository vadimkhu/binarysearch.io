/*
  Mad Max
  Question 14 of 953

  https://binarysearch.com/problems/Mad-Max
*/

vector<int> solve(vector<int>& nums, int k) {
    vector<int> res;
    size_t n = nums.size();
    
    for (int i = 0; i <= n - k; i++) { 
        int max_n = nums[i]; 
        for (int j = 1; j < k; j++) { 
            if (nums[i + j] > max_n) 
                max_n = nums[i + j]; 
        } 
        res.push_back(max_n); 
    }
    
    return res;
}
