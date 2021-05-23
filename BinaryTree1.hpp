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
    
        struct Node {
        T data;
        Node *left = nullptr;
        Node *right = nullptr;
        Node(T info): data(info), left(nullptr), right(nullptr){}
        };

        Node *root=nullptr;

        

        public:
            BinaryTree<T>(){} // empty constructor
            BinaryTree<T> add_root(const T& data){
                if(root==nullptr){ // if root doesn't exist --> creat new root
                    root = new Node(data);   
                }
                else{   // if root exist already --> update data of root
                    root->data=data;
                }
                return *this;
            }        

            BinaryTree<T> add_left(const T& exist,const T& New){
                if(root==nullptr){
                    throw "Exepction: binary tree is empty, no root created!";
                }
                // cout<<"add_left"<<endl;
                stack<Node*> s;
                   Node *curr = root;
                   while (curr != nullptr || !s.empty())
                   {   
                       
                       while (curr !=  NULL)
                       {
                           s.push(curr);
                           curr = curr->left;
                       }

                       curr = s.top();
                       s.pop();
                       if(curr->data==exist){
                           if(curr->left==nullptr){
                            curr->left=new Node(New);
                           }
                           else{
                             curr->left->data=New;
                           }
                            return *this;
                       }
                       curr = curr->right;
                   }
            throw std::invalid_argument{"this node isn't in the tree"};
            }

            BinaryTree<T> add_right(const T& exist,const T& New){
                 if(root==nullptr){
                    throw (string)"there is no root yes";
                }
                // cout<<"add_right"<<endl;
                stack<Node*> s;
                   Node *curr = root;
                   while (curr != nullptr || !s.empty())
                   {   
                       
                       while (curr !=  NULL)
                       {
                           s.push(curr);
                           curr = curr->left;
                       }

                       curr = s.top();
                       s.pop();
                       if(curr->data==exist){
                            if(curr->right==nullptr){
                                curr->right=new Node(New);
                           }
                           else{
                             curr->right->data=New;
                           }
                            // cout<<"add "<<New<<" to "<<exist<<endl;
                            return *this;
                       }
                       curr = curr->right;
                   }
            throw std::invalid_argument{"this node isn't in the tree"};
            }

 class iterator{

	  private:
        stack<Node*> s;
        string Order;
		Node* current_node;
        list<Node*> PostList;

	public:

		iterator(string order, Node* ptr=nullptr):current_node(ptr){
                Order=order;
                if(current_node!=nullptr){
                    if(order=="pre"){//preorder
                        if(current_node->right!=nullptr){
                            s.push(current_node->right);
                        }
                        if(current_node->left!=nullptr){
                            s.push(current_node->left);
                        }
                    }
                    else if(order=="in"){//inorder
                        while (current_node!=nullptr)
                        {
                          s.push(current_node);
                          current_node=current_node->left;
                        } 
                        current_node=s.top();
                        s.pop();
                    }
                    else{
                        while(current_node != nullptr || !s.empty()){
                            if(current_node != nullptr){
                                s.push(current_node);
                                current_node = current_node->left;
                            }else{
                                Node *temp = s.top()->right;
                                if (temp == nullptr) {
                                    temp = s.top();
                                    s.pop();
                                    PostList.push_back(temp);
                                    while (!s.empty() && temp == s.top()->right) {
                                        temp = s.top();
                                        s.pop();
                                        PostList.push_back(temp);
                                    }
                                } else {
                                    current_node = temp;
                                }
                            }
                        }
                        current_node=PostList.front();   
                        PostList.pop_front(); 
                    }
    		    }
        }

		T& operator*() const {
			return current_node->data;
		}

		T* operator->() const {
			return &(current_node->data);
		}

		// ++i;
		iterator& operator++() {
            if(Order=="pre"){
                if(s.empty()){
                    current_node=nullptr;
                    return *this;
                }
                current_node=s.top();
                s.pop();
    
                if(current_node->right!=nullptr){
                    s.push(current_node->right);
                }
                if(current_node->left!=nullptr){
                    s.push(current_node->left);
                }
            }
            else if(Order=="in"){
                if(!s.empty() || current_node->right!=nullptr){
                    current_node=current_node->right;

                    while(current_node!=nullptr){
                        s.push(current_node);
                        current_node=current_node->left;
                    }
                    current_node=s.top();
                    s.pop();
                    }
                else{
                    current_node=nullptr;
                    }
            }
            else{
                if(PostList.size()!=0){
                current_node=PostList.front();   
                PostList.pop_front();   
                }
                else current_node=nullptr;
            }
		return *this;
		}

		// i++;
		const iterator operator++(int) {
			iterator tmpIT= *this;
            if(Order=="pre"){
                if(s.empty()){
                    current_node=nullptr;
                    return *this;
                }
                current_node=s.top();
                s.pop();
    
                if(current_node->right!=nullptr){
                    s.push(current_node->right);
                }
                if(current_node->left!=nullptr){
                    s.push(current_node->left);
                }
            }
            else if(Order=="in"){
                if(!s.empty() || current_node->right!=nullptr){
                    current_node=current_node->right;

                    while(current_node!=nullptr){
                        s.push(current_node);
                        current_node=current_node->left;
                    }
                    current_node=s.top();
                    s.pop();
                    }
                else{
                    current_node=nullptr;
                    }
            }
            else{
                if(PostList.size()!=0){
                current_node=PostList.front();   
                PostList.pop_front();   
                }
                else current_node=nullptr;
            }
			return tmpIT;
		}

		bool operator==(const iterator& other) const {
			return current_node == other.current_node;
		}

		bool operator!=(const iterator& other) const {
			return current_node != other.current_node;
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

            friend std::ostream& operator<<(std::ostream& os, const BinaryTree<T> &bt){
                os<<"__________________\nPRINT TREE(preorder)\n----------------\n";
                if (bt.root == NULL)
                    return os;
                stack<Node*> s;
                s.push(bt.root);
            
                while (!s.empty()) {
                    Node* node = s.top();
                    os<<node->data<<" ";
                    s.pop();
                    if (node->right)
                        s.push(node->right);
                    if (node->left)
                        s.push(node->left);
                }
                os<<"\n__________________\n";
                return os;
            }

    };
}