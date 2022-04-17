#ifndef BINARYTREE_BINTREE_H
#define BINARYTREE_BINTREE_H
#include <iostream>

template<typename T>
class BinTree
{
public:
    struct Node
    {
        T	    value;
        int		count;
        Node*	top;
        Node*	left;
        Node*	right;
        Node() :
                value{ T(NULL) }, count{ 0 }, top{ nullptr }, left{ nullptr }, right{ nullptr }
        {}
        explicit Node(Node* other) :
                value{ std::move(other->value) }, count{ std::move(other->count) }, top{ std::move(other->top) }, left{ std::move(other->left) }, right{ std::move(other->right) }
        {}
        explicit Node(T ch) :
                value{ std::move(ch) }, count{ 1 }, top{ nullptr }, left{ nullptr }, right{ nullptr }
        {}
    };
    BinTree();
    explicit BinTree(typename BinTree<T>::Node*);
    ~BinTree();
    void Delete(typename BinTree<T>::Node*);
    typename BinTree<T>::Node* insert(const T&);

    [[nodiscard]] int size()const;
    [[nodiscard]] typename BinTree<T>::Node* getRoot()const;
    [[nodiscard]] typename BinTree<T>::Node* find(const char&)const;

    void inOrder()const;
    void inOrder(const typename BinTree<T>::Node*)const;

    [[nodiscard]] int heightTree(const typename BinTree<T>::Node*)const;
    void levelOrder()const;
    void levelOrder(const typename BinTree<T>::Node*)const;
    void levelOrder(const typename BinTree<T>::Node*, int)const;

    [[nodiscard]] int AnzahlKnoten(typename BinTree<T>::Node*)const;
private:
    typename BinTree<T>::Node* root;
    int sz{};
};

#include "../Source/BinTree.tpp"

#endif //BINARYTREE_BINTREE_H
