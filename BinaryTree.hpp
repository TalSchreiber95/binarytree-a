#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stack>
#include <string>
#include <list>


namespace ariel{

    template<class T>
    class BinaryTree{
        
        struct Node{ // Node's structure
            Node* right=nullptr;
            Node* left= nullptr;
            T data;
            Node(T d): data(d),right(nullptr),left(nullptr){}
        };
        Node* root;

        public:
        BinaryTree<T>(){ root(nullptr)};

        BinaryTree<T> add_root(const T& d){
                if(root==nullptr){ // if root doesn't exist --> creat new root
                    root = new Node(d);   
                }
                else{   // if root exist already --> update data of root
                    root->data=d;
                }
                return *this;
        }

        // add_right\left adding by inorder traversing 
        BinaryTree<T> add_right(const T& perent,const T& child ){
            if(root==nullptr)
            {
                throw "Exepction: binary tree is empty, no root created!";
            }
            stack<Node*> stk;
            Node* itr=root;
            while (itr!=nullptr || !stk.empty)
            {
                /* until no left exist */
                while (itr!=NULL)
                {
                    s.push(itr);
                    itr=itr->left;
                }

                itr= itr.top();
                itr.pop();
                if(itr->data==perent){
                    if(itr->right!=nullptr){
                        itr.right=child;
                    }
                    else{
                       itr.right=new Node(child);
                    }
                }
                itr= itr->right;
            }
            throw "Exepction: Node is'nt exist in this tree!";
        } 
        // add_right\left adding by inorder traversing 
        BinaryTree<T> add_left(const T& perent,const T& child ){
            if(root==nullptr)
            {
                throw "Exepction: binary tree is empty, no root created!";
            }
            stack<Node*> stk;
            Node* itr=root;
            while (itr!=nullptr || !stk.empty)
            {
                /* Extrame left*/
                while (itr!=NULL)
                {
                    s.push(itr);
                    itr=itr->left;
                }

                itr= itr.top();
                itr.pop();
                if(itr->data==perent){
                    if(itr->left!=nullptr){
                        itr.left=child;
                    }
                    else{
                       itr.left=new Node(child);
                    }
                }
                itr= itr->right;
            }
            throw "Exepction: Node is'nt exist in this tree!";
        } 
        
        
 class iterator{

	private:
        stack<Node*> stk;
		Node* currNode;
        list<Node*> PostList;
        string Order;
	public:
    iterator(string order, Node* nodePtr=nullptr): currNode(nodePtr)
    {

    }
    T& operator*() const{
        return currNode->data;
    }
    // smart pointer TT*
    T* operator->() const{
        return &(currNode->data);
    }

 }
    };
}