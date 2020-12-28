/*
  Points on a Line
  Question 378 of 950
  
  https://binarysearch.com/problems/Points-on-a-Line
*/

struct pairhash {
public:
    template <typename T, typename U>
    size_t operator()(const std::pair<T, U> &x) const {
        return hash<T>()(x.first) ^ hash<U>()(x.second);
    }
};

int solve(vector<vector<int>>& coordinates) {
    int n = coordinates.size(); 
    if (n < 2) 
        return n; 
  
    int answer = 0; 
    int cur, overlaps, verticals, horizontals; 
    unordered_map<pair<int, int>, int, pairhash> slope; 
    for (int i = 0; i < n; i++) { 
        cur = overlaps = verticals = horizontals = 0; 
        for (int j = i + 1; j < n; j++) { 
            if (coordinates[i] == coordinates[j]) 
                overlaps++; 
            else if (coordinates[i][0] == coordinates[j][0]) 
                verticals++; 
            else if (coordinates[i][1] == coordinates[j][1])
                horizontals++;
            else { 
                int dx = coordinates[j][0] - coordinates[i][0]; 
                int dy = coordinates[j][1] - coordinates[i][1]; 
                int g = __gcd(dx, dy); 
                dx /= g; 
                dy /= g; 
                slope[{dx, dy}]++; 
                cur = max(cur, slope[{dx, dy}]); 
            } 
  
            cur = max(cur, max(horizontals, verticals)); 
        } 
        answer = max(answer, cur + overlaps + 1); 
        slope.clear(); 
    } 
  
    return answer;         
}
