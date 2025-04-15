class SegmentTree{
    vector<int>tree;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = 0;
        } else {
            int mid = (start + end) / 2;
            build( 2 * node + 1, start, mid);
            build( 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query(int l, int r, int node, int start, int end) {
        if (l > end || r < start) {
            return 0; // No overlap
        }
        if (l <= start && end <= r) {
            return tree[node]; // Total overlap
        }
        int mid = (start + end) / 2;
        int leftSum = query(l, r, 2 * node + 1, start, mid);
        int rightSum = query(l, r, 2 * node + 2, mid + 1, end);
        return leftSum + rightSum; // Partial overlap
    }

    void update(int idx, int val, int node, int start, int end) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(idx, val, 2 * node + 1, start, mid);
            else
                update(idx, val, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
public : 
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, n - 1);
    }

    int query(int l, int r) {
        if(l > r) return 0;
        return query(l, r, 0, 0, n - 1);
    }
    void update(int idx) {
        update(idx, 1, 0, 0, n - 1);
    }
};
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        for(int i=0; i<nums2.size(); i++){
            mp[nums2[i]] = i;
        }
        
        SegmentTree tree(nums1.size());
        long long int ans = 0;

        for(int i=0; i<nums1.size(); i++){
            int nums2_ind = mp[nums1[i]];
            long long int commanele = tree.query(0,nums2_ind);
            long long int rightcommanele = (nums1.size() - nums2_ind - 1) - (i-commanele);
            ans = ans + (1ll* commanele * rightcommanele);

            tree.update(nums2_ind);
        }

        return ans;
    }
};