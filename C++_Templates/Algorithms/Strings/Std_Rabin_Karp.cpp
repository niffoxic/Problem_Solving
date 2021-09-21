# define d 256
const int key = 101;

void rbs(std::string text, std::string pattern, int n, int m){
    int h = 1;
    for(int i = 1; i <= m - 1; i++) h = (h * d) % key;

    int p = 0, t = 0;
    for(int i = 0; i < m; i++){
        p = (p * d + pattern[i]) % key;
        t = (t * d + text[i]) % key;
    }

    for(int i = 0; i < n - m; i++){
        if (p == t){
            bool flag = true;
            for(int j = 0; j < m; j++){
                if (text[i + j] != pattern[j]){
                    flag = false;
                    break;
                }
            }
            if (flag) cout << i << " ";
        }
        if (i < n - m) t = ((d * (t - text[i] * h)) + text[i + m]) % key;
        if (t < 0) t += key;
    }
}
