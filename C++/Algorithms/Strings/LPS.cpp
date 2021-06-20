
// 0(N)
void fill_lps(std::string res, int *lps){
    int n = res.length();
    int pointing = 0;
    int index = 1;
    lps[0] = 0;

    while (index < n){
        if (res[index] == res[pointing]){
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
