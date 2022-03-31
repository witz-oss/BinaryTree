#include "../Header/BinTree.h"
#include <iostream>

template<typename T>
BinTree<T>::BinTree()
{
    root = new Node{};
    sz = 0;
}

template<typename T>
BinTree<T>::BinTree(typename BinTree<T>::Node* node)
{
    root = std::move(node);
    sz++;
}

template<typename T>
BinTree<T>::~BinTree()
{
    Delete(root);
}

template<typename T>
void BinTree<T>::Delete(typename BinTree<T>::Node* nodeTMP)
{
    if (nodeTMP == nullptr)
        return;

    Delete(nodeTMP->left);
    Delete(nodeTMP->right);
    delete nodeTMP;
}

template<typename T>
int BinTree<T>::size() const
{
    return sz;
}

template<typename T>
typename BinTree<T>::Node* BinTree<T>::wurzel() const
{
    return root;
}

template<typename T>
typename BinTree<T>::Node* BinTree<T>::find(const char& val) const
{
    typename BinTree::Node* tmpNode = std::move(root);
    while(tmpNode != nullptr) {
        if (tmpNode->value < val)
            tmpNode = std::move(tmpNode->right);
        else if (tmpNode->value > val)
            tmpNode = std::move(tmpNode->left);
        else
            return tmpNode;
    }
    std::cout << "dont find" << '\n';
    return nullptr;
}

template<typename T>
typename BinTree<T>::Node* BinTree<T>::insert(const T& val)
{
    if (root->value == NULL)
    {
        root->value = val;
        root->count++;
        sz++;
        return root;
    }

    typename BinTree<T>::Node* nodeTMP{ this->root };
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

template<typename T>
typename BinTree<T>::Node* BinTree<T>::insertKnotenWurzel(const T& val)
{

}

template<typename T>
void BinTree<T>::inOrder()const
{
    typename BinTree<T>::Node* node{ this->root };
    inOrder(node);
}

template<typename T>
void BinTree<T>::inOrder(const typename BinTree<T>::Node* nodeTMP)const
{
    if (nodeTMP == nullptr)
        return;

    inOrder(nodeTMP->left);
    std::cout << nodeTMP->value << " ";
    inOrder(nodeTMP->right);
}

template<typename T>
int BinTree<T>::heightTree(const typename BinTree<T>::Node* nodeTMP)const
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

template<typename T>
void BinTree<T>::levelOrder()const
{
    typename BinTree<T>::Node* node{ this->root };
    levelOrder(node);
}

template<typename T>
void BinTree<T>::levelOrder(const typename BinTree<T>::Node* nodeTMP)const
{
    int level = this->heightTree(nodeTMP);
    for (int i{0}; i <= level; i++)
        levelOrder(nodeTMP, i);
}

template<typename T>
void BinTree<T>::levelOrder(const typename BinTree<T>::Node* nodeTMP, int level)const
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

template<typename T>
int BinTree<T>::AnzahlKnoten(typename BinTree<T>::Node* nodeTMP) const
{
    if (nodeTMP == nullptr)
        return 0;
    return 1 + AnzahlKnoten(nodeTMP->left) + AnzahlKnoten(nodeTMP->right);
}
