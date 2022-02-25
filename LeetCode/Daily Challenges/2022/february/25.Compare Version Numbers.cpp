class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, n = version1.size(), m = version2.size(), left = 0, right = 0;
        while (i < n || j < m) {
            while (i < n && version1[i] != '.') {
                left = left * 10 + (version1[i] - '0');
                i++;
            }
            while (j < m && version2[j] != '.') {
                right = right * 10 + (version2[j] - '0');
                j++;
            }
            if (left > right) return 1;
            if (left < right) return -1;
            i++, j++;
            left = 0, right = 0;
        }
        return 0;
    }
};
