#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
private:
    TreeNode* root;

public:
    ExpressionTree() : root(nullptr) {}

    // Function to construct expression tree from prefix expression
    void constructTree(const string& prefix) {
        stack<TreeNode*> stk;
        for (int i = prefix.size() - 1; i >= 0; --i) {
            char ch = prefix[i];
            TreeNode* newNode = new TreeNode(ch);
            if (isdigit(ch) || isalpha(ch)) {
                stk.push(newNode);
            } else {
                newNode->left = stk.top();
                stk.pop();
                newNode->right = stk.top();
                stk.pop();
                stk.push(newNode);
            }
        }
        root = stk.top();
    }

    // Function to traverse the expression tree using post-order traversal (non-recursive)
    void postOrderTraversal() {
        if (!root)
            return;

        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* prev = nullptr;
        while (!stk.empty()) {
            TreeNode* current = stk.top();
            if (!prev || prev->left == current || prev->right == current) {
                if (current->left)
                    stk.push(current->left);
                else if (current->right)
                    stk.push(current->right);
            } else if (current->left == prev) {
                if (current->right)
                    stk.push(current->right);
            } else {
                cout << current->data << " ";
                stk.pop();
            }
            prev = current;
        }
    }

    // Function to delete the entire tree
    void deleteTree(TreeNode* root) {
        if (!root)
            return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    ~ExpressionTree() {
        deleteTree(root);
    }
};

int main() {
    string prefixExpression = "+--a*bc/def";
    ExpressionTree expTree;
    expTree.constructTree(prefixExpression);

    cout << "Post-order traversal: ";
    expTree.postOrderTraversal();
    cout << endl;

    return 0;
}

