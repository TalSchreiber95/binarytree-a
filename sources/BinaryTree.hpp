#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stack>
#include <string>
#include <list>
using namespace std;

namespace ariel
{

    template <class T>
    class BinaryTree
    {

        struct Node
        { // Node's structure
            Node *right;
            Node *left;
            T data;
            Node(T d) : data(d), right(nullptr), left(nullptr) {}
        };
        Node *root = nullptr;

    public:
        BinaryTree<T>() {}

        BinaryTree<T> add_root(const T &d)
        {
            if (root == nullptr)
            { // if root doesn't exist --> creat new root
                root = new Node(d);
            }
            else
            { // if root exist already --> update data of root
                root->data = d;
            }
            return *this;
        }

        // add_right\left adding by inorder traversing
        BinaryTree<T> add_right(const T &perent, const T &child)
        {
            if (root == nullptr)
            {
                throw "Exepction: binary tree is empty, no root created!";
            }
            stack<Node *> stk;
            Node *itr = root;
            while (itr != nullptr || !stk.empty())
            {
                /* until no left exist */
                while (itr != NULL)
                {
                    stk.push(itr);
                    itr = itr->left;
                }

                itr = stk.top();
                stk.pop();
                if (itr->data == perent)
                {
                    if (itr->right != nullptr)
                    {
                        itr->right->data = child;
                    }
                    else
                    {
                        itr->right = new Node(child);
                    }
                    return *this;
                }
                itr = itr->right;
            }
            throw "Exepction: Node is'nt exist in this tree!";
        }
        // add_right\left adding by inorder traversing
        BinaryTree<T> add_left(const T &perent, const T &child)
        {
            if (root == nullptr)
            {
                throw "Exepction: binary tree is empty, no root created!";
            }
            stack<Node *> stk;
            Node *itr = root;
            while (itr != nullptr || !stk.empty())
            {
                /* Extrame left*/
                while (itr != NULL)
                {
                    stk.push(itr);
                    itr = itr->left;
                }

                itr = stk.top();
                stk.pop();
                if (itr->data == perent)
                {
                    if (itr->left != nullptr)
                    {
                        itr->left->data = child;
                    }
                    else
                    {
                        itr->left = new Node(child);
                    }
                    return *this;
                }
                itr = itr->right;
            }
            throw "Exepction: Node is'nt exist in this tree!";
        }

        class iterator
        {

        private:
            stack<Node *> stk;
            Node *_currNode;
            list<Node *> PostList;
            string _type;

        public:
            //should update the _currNode acording to order type that required (inOrder , preOrder, postOrder)
            // using case and order that define by strings
            iterator(string type, Node *nodePtr = nullptr) : _currNode(nodePtr)
            {
                // _type = type;
                // int gType = generateType(_type);
                // if (_currNode != nullptr)
                // {
                //     switch (gType)
                //     {
                //     case -1: // _gType=-1 --> which means Error
                //         throw "Exception: type of table doesn't exist";
                //         break;
                //     case 1: // inOrder ( L , Ro , Ri )
                //         _currNode = extremelyLeft(_currNode);
                //         break;
                //     case 2: // preOrder ( Ro , L , Ri )
                //         if (_currNode->right != nullptr)
                //         {
                //             stk.push(_currNode->right);
                //         }
                //         if (_currNode->left != nullptr)
                //         {
                //             stk.push(_currNode->left);
                //         }
                //         break;
                //     case 3: // postOrder ( L , Ri , Ro ) // should check it
                //         Node *firstSon = extremelyLeft(_currNode);
                //         while (hasRightSon(firstSon))
                //         {
                //             firstSon = extremelyLeft(firstSon);
                //         }
                //         _currNode = firstSon;
                //         break;
                //     }
                // }
            }
            Node *extremelyLeft(Node *n)
            {
                // while (stk.pop()==nullptr){}
                while (_currNode != nullptr)
                {
                    stk.push(_currNode);
                    _currNode = _currNode->left;
                }
                Node *s = stk.top();
                return s;
            }
            bool hasRightSon(Node *n)
            {
                return n->right != nullptr;
            }
            int generateType(string s)
            {
                if (s == "in")
                {
                    return 1;
                }
                else if (s == "pre")
                {
                    return 2;
                }
                else if (s == "post")
                {
                    return 3;
                }
                return -1;
            }
            // data's pointer
            T &operator*() const
            {
                return _currNode->data;
            }

            // smart pointer T*
            T *operator->() const
            {
                return &(_currNode->data);
            }
            iterator &operator++()
            {
                return *this;
            }
            const iterator operator++(int)
            {
                iterator tmp = *this;
                return tmp;
            }
            bool operator==(const iterator &other) const
            {
                return _currNode->data == other._currNode->data;
            }

            bool operator!=(const iterator &other) const
            {
                return _currNode->data != other._currNode->data;
            }
        };
        iterator begin_preorder()
        {
            return iterator("pre",root);
            // return iterator("pre", root);
        }
        iterator end_preorder()
        {
            return iterator("pre",root);

            // return iterator("pre", nullptr);
        }
        iterator begin_inorder()
        {
            return iterator("pre",root);

            // return iterator("in", root);
        }
        iterator end_inorder()
        {
            return iterator("pre",root);

            // return iterator("in", nullptr);
        }
        iterator begin_postorder()
        {
            return iterator("pre",root);

            // return iterator("post", root);
        }
        iterator end_postorder()
        {
            return iterator("pre",root);

            // return iterator("post", nullptr);
        }
        iterator begin()
        {
            return iterator("pre",root);

            // return iterator("in", root);
        }
        iterator end()
        {
            return iterator("pre",root);

            // return iterator("in", nullptr);
        }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &bt)
        {
            os << "\nPrint Tree\n";
            return os;
        }
    };
}