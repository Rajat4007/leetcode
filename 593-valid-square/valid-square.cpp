class Solution {
public:
    int distance(vector<int>& x, vector<int>& y) {
        int a = y[0] - x[0];
        int b = y[1] - x[1];
        return a*a + b*b;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> store;
        store.push_back(distance(p1,p2));
        store.push_back(distance(p2,p3));
        store.push_back(distance(p3,p4));
        store.push_back(distance(p4,p1));
        store.push_back(distance(p1,p3));
        store.push_back(distance(p2,p4));

        sort(store.begin(),store.end());

        if(store[0]>0 && store[0] == store[1] && store[1] == store[2] && store[2] == store[3] && store[4] == store[5] && store[3] < store[4] ) return true;
        return false;
    }
};