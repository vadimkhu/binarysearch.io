/*
  IP Address Combinations
  Question 218 of 975

  https://binarysearch.com/problems/IP-Address-Combinations
*/

bool is_valid(string ip) { 
    vector<string> ips;
    stringstream ss(ip); 
    string item;
    while (getline(ss, item, '.'))
        ips.push_back(item);

    for (int i = 0; i < ips.size(); i++) { 
        if (ips[i].length() > 3 
            || stoi(ips[i]) < 0 
            || stoi(ips[i]) > 255) 
            return false; 
  
        if (ips[i].length() > 1 
            && stoi(ips[i]) == 0) 
            return false; 
  
        if (ips[i].length() > 1 
            && stoi(ips[i]) != 0 
            && ips[i][0] == '0') 
            return false; 
    } 
    return true; 
} 

vector<string> solve(string ip) {
    int len = ip.length(); 
    vector<string> ans; 

    if (len > 12 || len < 4) return ans;

    string check = ip; 
    for (int i = 1; i < len - 2; i++) { 
        for (int j = i + 1; j < len - 1; j++) { 
            for (int k = j + 1; k < len; k++) { 
                check = check.substr(0, k) + "."
                        + check.substr(k, len - k + 2); 
                check 
                    = check.substr(0, j) + "."
                      + check.substr(j, len - j + 3); 
                check 
                    = check.substr(0, i) + "."
                      + check.substr(i, len - i + 4); 
  
                if (is_valid(check)) { 
                    ans.push_back(check); 
                } 
                check = ip; 
            } 
        } 
    }     
    return ans;
}
