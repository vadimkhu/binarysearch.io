/*
  Insertion Index in Sorted List
  Question 34 of 987

  https://binarysearch.com/problems/Insertion-Index-in-Sorted-List
*/

int solve(vector<int>& nums, int target) {
    int answer = 0;
    for (int index = 0; index < nums.size() && target >= nums[index]; index++) {
        answer++;
    }
    return answer;
}
