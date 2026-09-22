//This code i have copied from gemini as i have not studied segment tree
#include <vector>
#include <array>

using namespace std;

class Solution {
    struct Node {
        int prod;
        // Fixed-size array allocation remove karega (k <= 5 hota hai)
        int count[5];
        
        Node() {
            prod = 1;
            for (int i = 0; i < 5; ++i) count[i] = 0;
        }
    };

    int n;
    int k_mod;
    vector<Node> tree;

    inline void mergeNodes(const Node& left, const Node& right, Node& res) {
        res.prod = (left.prod * right.prod) % k_mod;

        for (int r = 0; r < k_mod; ++r) {
            res.count[r] = left.count[r];
        }

        for (int r = 0; r < k_mod; ++r) {
            if (right.count[r] > 0) {
                int new_rem = (left.prod * r) % k_mod;
                res.count[new_rem] += right.count[r];
            }
        }
    }

    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            tree[node] = Node();
            int rem = nums[start] % k_mod;
            tree[node].prod = rem;
            tree[node].count[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        mergeNodes(tree[2 * node], tree[2 * node + 1], tree[node]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % k_mod;
            tree[node] = Node();
            tree[node].prod = rem;
            tree[node].count[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        mergeNodes(tree[2 * node], tree[2 * node + 1], tree[node]);
    }

    void query(int node, int start, int end, int l, int r, Node& res) {
        if (l <= start && end <= r) {
            res = tree[node];
            return;
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) {
            query(2 * node, start, mid, l, r, res);
            return;
        }
        if (l > mid) {
            query(2 * node + 1, mid + 1, end, l, r, res);
            return;
        }

        Node leftRes, rightRes;
        query(2 * node, start, mid, l, r, leftRes);
        query(2 * node + 1, mid + 1, end, l, r, rightRes);
        mergeNodes(leftRes, rightRes, res);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        k_mod = k;
        tree.assign(4 * n, Node());

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int target_x = q[3];

            update(1, 0, n - 1, idx, val);

            Node res;
            query(1, 0, n - 1, start, n - 1, res);

            ans.push_back(res.count[target_x]);
        }

        return ans;
    }
};