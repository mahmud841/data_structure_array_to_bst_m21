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

Node *convertBst(int a[], int n, int l, int r)
{
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;
    Node *root = new Node(a[mid]);
    Node *leftNode = convertBst(a, n, l, mid - 1);
    Node *rightNode = convertBst(a, n, mid + 1, r);
    root->left = leftNode;
    root->right = rightNode;
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

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Node *root = convertBst(a, n, 0, n - 1);
    levelOrder(root);
    return 0;
}