/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/


void traverseLeftBoundary (TreeNode <int> *node, vector <int> &result) {
    if (node == NULL || (node -> left == NULL && node -> right == NULL)) {
        return;
    }

    result.push_back(node -> data);
    if (node -> left) {
        traverseLeftBoundary(node -> left, result);
    }

    else {
        traverseLeftBoundary(node -> right, result);
    }
}

void traverseLeafNodes(TreeNode <int> *node, vector <int> &result) {
    if (node == NULL) {
        return ;
    }

    if (node -> left == NULL && node -> right == NULL) {
        result.push_back(node -> data);
        return ;
    }

    traverseLeafNodes(node -> left, result);
    traverseLeafNodes(node -> right, result);
}

void traverseRightBoundary(TreeNode <int> *node, vector <int> &result) {
    if (node == NULL || (node -> left == NULL && node -> right == NULL)) {
        return;
    }

    if (node -> right) {
        traverseRightBoundary(node -> right, result);
    }

    else {
        traverseRightBoundary(node -> left, result);
    }

    result.push_back(node -> data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector <int> result;
    if (!root) return result;

    result.push_back(root -> data);
    traverseLeftBoundary(root -> left, result);
    traverseLeafNodes(root, result);
    traverseRightBoundary(root -> right, result);
    return result;
}
