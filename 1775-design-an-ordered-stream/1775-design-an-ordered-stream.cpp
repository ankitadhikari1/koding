class OrderedStream {
private:
    vector<string> s;
    int ptr = 1, size;
public:
    OrderedStream(int n) : s(n + 1) {
        size = n + 1;
    }
    vector<string> insert(int idKey, string value) {
        s[idKey] = value;
        vector<string> res;
        while(ptr < size && !s[ptr].empty()) res.push_back(s[ptr++]);
        return res;
    }
};