You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

Constraints:

1 <= descriptions.length <= 104
descriptions[i].length == 3
1 <= parenti, childi <= 105
0 <= isLefti <= 1
The binary tree described by descriptions is valid.


//solution

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet; 
        for(vector<int>& vec : descriptions) { 
            int parent = vec[0];
            int child  = vec[1];
            int isLeft = vec[2];

            if(mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }
            if(isLeft == 1) { 
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }
            childSet.insert(child);
        }
        for(vector<int>& vec : descriptions) { 
            int parent = vec[0];
            if(childSet.find(parent) == childSet.end()) { 
                return mp[parent];
            }
        }
        return NULL; 
    }
};


t.c. =o (n)
