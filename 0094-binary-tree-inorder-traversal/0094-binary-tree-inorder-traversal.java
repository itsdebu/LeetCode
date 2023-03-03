/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();

        if(root == null) return result;

        Stack<TreeNode> stack = new Stack<>();
        HashSet<TreeNode> set = new HashSet<>();
        stack.push(root);

        while(!stack.isEmpty()) {
            TreeNode current = stack.pop();
            if(set.contains(current) || (current.left == null && current.right == null)) {
                result.add(current.val);
                continue;
            }

            if(current.right != null) stack.push(current.right);
            stack.push(current);
            if(current.left != null) stack.push(current.left);

            set.add(current);
        }

        return result;
    }
}