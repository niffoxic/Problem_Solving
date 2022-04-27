class DisjointSet {
public:
    DisjointSet(int size) {
        _rank = std::vector<int>(size, 0);
        _parent = std::vector<int>(size, 0);
        while (--size >= 0) {
            _parent[size] = size;
        }
    }

    int find(int i) {
        if (_parent[i] != i) {
            _parent[i] = find(_parent[i]);
        }
        return _parent[i];
    }

    void merge(int i, int j) {
        int root1 = find(i);
        int root2 = find(j);
        if (_rank[root1] > _rank[root2]) {
            _parent[root2] = root1;
        } else {
            _parent[root1] = root2;
            if (_rank[root1] == _rank[root2]) {
                ++_rank[root2];
            }
        }
    }

private:
    std::vector<int> _parent;
    std::vector<int> _rank;
};

using Component = std::vector<int>;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DisjointSet ds(s.size());
        for (const auto& pair: pairs) {
            ds.merge(ds.find(pair[0]), ds.find(pair[1]));
        }
        std::unordered_map<int, Component> components;
        for (int i = 0; i < s.size(); ++i) {
            int root = ds.find(i);
            components[root].emplace_back(i);
        }
        std::string answer(s.size(), ' ');
        for (auto& [_, component] : components) {
            fillAnswer(answer, s, component);
        }
        return answer;
    }
private:
    static void fillAnswer(std::string& answer, const std::string& s, Component& component) {
        if (component.empty()) {
            return;
        }

        std::sort(component.begin(), component.end());
        std::array<int, 26> count{};
        for (const auto i: component) {
            ++count[s[i] - 'a'];
        }
        std::vector<char> characters(component.size(), ' ');
        for (std::size_t i = 0, j = 0; i < 26; ++i) {
            while (--count[i] >= 0) {
                characters[j++] = char('a' + i);
            }
        }
        for (std::size_t i = 0; i < component.size(); ++i) {
            answer[component[i]] = characters[i];
        }
    }
};
