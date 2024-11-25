#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *inputTree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        // 1.ber kore ana
        Node *parent = q.front();
        q.pop();

        // 2.sob kaj korte hobe
        int l, r;
        cin >> l >> r;
        Node *newLeft;
        Node *newRight;
        if (l == -1)
            newLeft = NULL;
        else
            newLeft = new Node(l);
        if (r == -1)
            newRight = NULL;
        else
            newRight = new Node(r);

        parent->left = newLeft;
        parent->right = newRight;
        // 3. children input push kore ante hobe
        if (parent->left)
            q.push(parent->left);
        if (parent->right)
            q.push(parent->right);
    }
    return root;
}

void levelOrder(Node *root)
{

    if (root == NULL)
    {
        cout << "Tree Empty" << endl;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *j = q.front();
        q.pop();
        // jabotiyo kaj aibar korte hobe

        cout << j->val << " ";

        // children rakha
        //  if(f->left !=NULL) q.push(f->left);
        //  if(f->right !=NULL) q.push(f->right);
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void insert(Node *&root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
        return;
    }
    if (x < root->val)
    {
        if (root->left == NULL)
        {
            root->left = new Node(x);
        }
        else
        {
            insert(root->left, x);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new Node(x);
        }
        else
        {
            insert(root->right, x);
        }
    }
}

int main()
{
    Node *root = inputTree();
    int x;
    cin >> x;
    insert(root, 13);
    insert(root, 32);
    insert(root, 27);
    insert(root, 22);
    levelOrder(root);
    return 0;
}