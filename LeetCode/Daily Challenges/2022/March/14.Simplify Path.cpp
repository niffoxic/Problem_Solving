class Solution {
public:
    string simplifyPath(string& path) {

        stack<string> stck;
        string res;

        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') continue;
            string temp;
            while (i < path.size() && path[i] != '/') {
                temp += path[i];
                ++i;
            }
            if (temp == ".") continue;
            else if (temp == "..") {
                if (!stck.empty())
                    stck.pop();
            } else stck.push(temp);
        }
        while (!stck.empty()) {
            res = "/" + stck.top() + res;
            stck.pop();
        }
        if (res.size() == 0) return "/";
        return res;
    }
};
