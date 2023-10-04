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
    //we have to iterate through bottum to up.
    // 1- covered from childrens.
    // 0- no need of camera at that node.
    // -1 - need camera at that node.
    // if root is null then it's handeled by its parent means return 1
    int min_camera(TreeNode* root,int &camera)
    {
        if(!root)return 1;

        int left = min_camera(root->left,camera);
        int right = min_camera(root->right,camera);

        if(left == -1 || right == -1)
        {
            camera++;
            return 0;
        }
        if(left==0 || right ==0)return 1;

        return -1;
        
    }
    int minCameraCover(TreeNode* root) {
        int camera = 0;
        if(min_camera(root,camera)==-1)return 1+camera;
        return camera;
    }
};