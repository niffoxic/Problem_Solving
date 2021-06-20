

void fill_lps(std::string pattern, int *lps){
    int n = pattern.length();
    int pointing = 0;
    int index = 1;
    lps[0] = 0;

    while (index < n){
        if (pattern[index] == pattern[pointing]){
            pointing++;
            lps[index] = pointing;
            index++;
        }else{
            if (pointing == 0){
                lps[index] = 0;
                index++;
            }else{
                pointing = lps[pointing - 1];
            }
        }
    }
}

void kmp(std::string text, std::string pattern){
    int n = text.length();
    int m = pattern.length();
    int lps[m];
    fill_lps(pattern, lps);
    int index = 0, p_index = 0;

    while (index < n)
    {
        if (text[index] == pattern[p_index])
        {
            index++; p_index++;
        }
        if (p_index == m)
        {
            cout << index - p_index << " ";
            p_index = lps[p_index - 1];
        }else if (index < n && text[index] != pattern[p_index])
        {
            if (p_index == 0) index++;
            else{
                p_index = lps[p_index - 1];
            }
        }
    }

}
