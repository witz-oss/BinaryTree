#include "../Header/BinTree.h"

BinTree::BinTree()
{
    root = new Node{};
    sz = 0;
}

BinTree::BinTree(Node* node)
{
    root = node;
    sz++;
}

BinTree::~BinTree()
{
    Delete(root);
}
void BinTree::Delete(Node* nodeTMP)
{
    if (nodeTMP == nullptr)
        return;

    Delete(nodeTMP->left);
    Delete(nodeTMP->right);
    delete nodeTMP;
}

int BinTree::size() const
{
    return sz;
}

typename BinTree::Node* BinTree::wurzel() const
{
    return root;
}

typename BinTree::Node* BinTree::find(const char& val) const
{
    BinTree::Node* tmpNode{root};
    while(tmpNode != nullptr) {
        if (tmpNode->value < val)
            tmpNode = tmpNode->right;
        else if (tmpNode->value > val)
            tmpNode = tmpNode->left;
        else
            return tmpNode;
    }
    std::cout << "dont find" << '\n';
    return nullptr;
}

typename BinTree::Node* BinTree::insert(const char& val)
{
    if (root->value == NULL)
    {
        root->value = val;
        root->count++;
        sz++;
        return root;
    }

    Node* nodeTMP{ this->root };
    while(true) {
        if (nodeTMP->value == val) {
            nodeTMP->count++;
            sz++;
            return nodeTMP;
        }
        if (nodeTMP->value < val) {
            if (nodeTMP->right == nullptr) {
                nodeTMP->right = new Node{val};
                nodeTMP->right->top = nodeTMP;
                sz++;
                return nodeTMP->right;
            }
            nodeTMP = nodeTMP->right;
        }
        else if (nodeTMP->value > val) {
            if (nodeTMP->left == nullptr) {
                nodeTMP->left = new Node{val};
                nodeTMP->left->top = nodeTMP;
                sz++;
                return nodeTMP->left;
            }
            nodeTMP = nodeTMP->left;
        }
    }
}

typename BinTree::Node* BinTree::insertKnotenWurzel(const char& val)
{

}

void BinTree::inOrder()const
{
    Node* node{ this->root };
    inOrder(node);
}
void BinTree::inOrder(const Node* nodeTMP)const
{
    if (nodeTMP == nullptr)
        return;

    inOrder(nodeTMP->left);
    std::cout << nodeTMP->value << " ";
    inOrder(nodeTMP->right);
}

int BinTree::heightTree(const Node* nodeTMP)const
{
    if (nodeTMP == 0)
        return 0;
    int left{};
    int right{};

    if (nodeTMP->left != NULL)
        left = heightTree(nodeTMP->left);
    else
        left = -1;

    if (nodeTMP->right != NULL)
        right = heightTree(nodeTMP->right);
    else
        right = -1;

    int max = left > right ? left : right;
    return max + 1;
}

void BinTree::levelOrder()const
{
    Node* node{ this->root };
    levelOrder(node);
}
void BinTree::levelOrder(const Node* nodeTMP)const
{
    int level = this->heightTree(nodeTMP);
    for (int i{0}; i <= level; i++)
        levelOrder(nodeTMP, i);
}
void BinTree::levelOrder(const Node* nodeTMP, int level)const
{
    if (nodeTMP == NULL)
        return;
    else if (level == 1 && nodeTMP != nullptr)
        std::cout << nodeTMP->value << " ";
    else if (level > 1)
    {
        if (nodeTMP != nullptr)
        {
            levelOrder(nodeTMP->left, level - 1);
            levelOrder(nodeTMP->right, level - 1);
        }
    }
}

int BinTree::AnzahlKnoten(Node* nodeTMP) const
{
    if (nodeTMP == nullptr)
        return 0;
    return 1 + AnzahlKnoten(nodeTMP->left) + AnzahlKnoten(nodeTMP->right);
}
