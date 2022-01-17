class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        unsigned long long massL = mass;
        for(auto i: asteroids){
            if (massL < i)
                return false;
            massL += i;
        }
        return true;
    }
};
