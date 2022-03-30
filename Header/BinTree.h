#ifndef BINARYTREE_BINTREE_H
#define BINARYTREE_BINTREE_H
#include <iostream>

class BinTree
{
public:
    struct Node
    {
        char	value;
        int		count;
        Node*	top;
        Node*	left;
        Node*	right;
        Node() :
                value{ NULL }, count{ 0 }, top{ nullptr }, left{ nullptr }, right{ nullptr }
        {}
        explicit Node(Node* other) :
                value{ other->value }, count{ other->count }, top{ other->top }, left{ other->left }, right{ other->right }
        {}
        explicit Node(char ch) :		//, Node* t = nullptr
                value{ ch }, count{ 1 }, top{ nullptr }, left{ nullptr }, right{ nullptr }
        {}
    };
    BinTree();
    BinTree(Node*);
    ~BinTree();
    void Delete(Node*);

    [[nodiscard]] int size()const;
    [[nodiscard]] Node* wurzel()const;
    [[nodiscard]] Node* find(const char&)const;

    Node* insert(const char&);
    Node* insertKnotenWurzel(const char&);

    void inOrder()const;
    void inOrder(const Node*)const;

    [[nodiscard]] int heightTree(const Node*)const;
    void levelOrder()const;
    void levelOrder(const Node*)const;
    void levelOrder(const Node*, int)const;

    [[nodiscard]] int AnzahlKnoten(Node*)const;
private:
    Node* root;
    int sz{};
};


#endif //BINARYTREE_BINTREE_H
