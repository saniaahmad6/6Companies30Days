/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector <int> v1,v2,ans;
    void inorder(TreeNode *root,vector<int> &v){
        if (root){
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }
    void merge(){
        int n=v1.size();
        int m=v2.size();
        int i=0,j=0;
        while (i<n && j<m){
            if (v1[i]<=v2[j]){
                ans.push_back(v1[i++]);
            }
            else if (v1[i]>v2[j]){
                ans.push_back(v2[j++]);
            }
            
        }
        for (;i<n;i++){
            ans.push_back(v1[i]);
        }
        for (;j<m;j++){
            ans.push_back(v2[j]);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1,v1);
        inorder(root2,v2);
        merge();
        return ans;
    }
};
