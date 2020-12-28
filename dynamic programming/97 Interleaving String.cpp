//
//  97 Interleaving String.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n + m != s3.size())
            return false;
        
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' ' + s3;
        f[0][0] = true;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i > 0 && s1[i] == s3[i + j])
                    f[i][j] = f[i][j] || f[i - 1][j];
                if(j > 0 && s2[j] == s3[i + j])
                    f[i][j] = f[i][j] || f[i][j - 1];
            }
        }
        
        return f[n][m];
    }
};
