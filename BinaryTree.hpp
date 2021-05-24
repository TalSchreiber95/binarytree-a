#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stack>
#include <string>
#include <list>
using namespace std;

namespace ariel{

    template<class T>
    class BinaryTree{
        
        struct Node{ // Node's structure
            Node* right;
            Node* left;
            T data;
            Node(T d): data(d),right(nullptr),left(nullptr){}
        };
        Node* root;

        public:
        BinaryTree<T>(): root(nullptr){}

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
                    stk->push(itr);
                    itr=itr->left;
                }

                // stk= stk->top();
                stk = stk->pop();
                if(itr->data==perent){
                    if(itr->right!=nullptr){
                        itr->right=child;
                    }
                    else{
                       itr->right=new Node(child);
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
                    stk->push(itr);
                    itr=itr->left;
                }

                // stk= stk->top();
                stk = stk->pop();
                if(itr->data==perent){
                    if(itr->left!=nullptr){
                        itr->left=child;
                    }
                    else{
                       itr->left=new Node(child);
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

        //should update the currNode acording to order type that required (inOrder , preOrder, postOrder)
        // using case and order that define by strings
        iterator(string order, Node* nodePtr=nullptr): currNode(nodePtr)
        {
            
        }   
        
        // data's pointer
        T& operator*() const{
            return currNode->data;
        }

        // smart pointer T*
        T* operator->() const{
            return &(currNode->data);
        }

};
            iterator begin_preorder(){
                return iterator("pre", root);
            }
            iterator end_preorder(){
                return iterator("pre", nullptr);
            }
            iterator begin_inorder(){
                return iterator("in", root);
            }
            iterator end_inorder(){
                return iterator("in", nullptr);
            }
            iterator begin_postorder(){
                return iterator("post", root);
            }
            iterator end_postorder(){
                return iterator("post", nullptr);
            }
            iterator begin(){
                return iterator("in", root);
            }
            iterator end(){
                return iterator("in", nullptr);
            }

    };
}