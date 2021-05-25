#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;

TEST_CASE("int Binary tree"){
    BinaryTree<int> btInt;
    CHECK_NOTHROW(btInt.add_root(0));
    CHECK_NOTHROW(btInt.add_root(1));
    CHECK_NOTHROW(btInt.add_left(1, 3));
    CHECK_NOTHROW(btInt.add_left(1, 2));
    CHECK_NOTHROW(btInt.add_right(1, 4));
    CHECK_THROWS(btInt.add_left(7,4)); //7 doesn't exist
    CHECK_NOTHROW(btInt.add_right(1,3));
    CHECK_NOTHROW(btInt.add_right(3,7));
    CHECK_NOTHROW(btInt.add_left(3,6));
    CHECK_NOTHROW(btInt.add_right(2, 5));
    CHECK_NOTHROW(btInt.add_left(2, 4));
    
    int inArr[]={4,2,5,1,6,3,7};
    int preArr[]={1,2,4,5,3,6,7};
    int postArr[]={4,5,2,6,7,3,1};
    int i=0;
    SUBCASE("check operator == , and check itertor increment"){
    for (auto it=btInt.begin_preorder(); it!=btInt.end_preorder(); ++it) {
        CHECK((*it)==preArr[i]);
        i++;
    }
    i=0;
    for (const int& element: btInt) { 
        CHECK(element==inArr[i]);
        i++;
    }
    i=0;
    for (auto it=btInt.begin_postorder(); it!=btInt.end_postorder(); ++it) {
        CHECK((*it)==postArr[i]);
        i++;
    }
    }

    SUBCASE("add to a twice node exist"){
        CHECK_NOTHROW(btInt.add_right(5,4)); 
        CHECK_NOTHROW(btInt.add_left(4, 1)); // there is a twice 4 nodes

        string in1="1,4,2,5,4,1,6,3,7," , in2="4,2,5,1,4,1,6,3,7,";  
        string pre1="1,2,4,1,5,4,3,6,7," , pre2="1,2,4,5,4,1,3,6,7,";
        string post1="1,4,4,5,2,6,7,3,1," , post2="4,1,4,5,2,6,7,3,1,";

        string ansPre,ansIn,ansPost;
        
        for (auto it=btInt.begin_postorder(); it!=btInt.end_postorder(); ++it) {
            ansPost+=to_string(*it);
            ansPost+=",";
        }
        for (auto it=btInt.begin_inorder(); it!=btInt.end_inorder(); ++it) {
            ansIn+=to_string(*it);
            ansIn+=",";
        }
        for (auto it=btInt.begin_preorder(); it!=btInt.end_preorder(); it++) {
            ansPre+=to_string(*it);
            ansPre+=",";
        }
        
        CHECK(((ansPre==pre1)||(ansPre==pre2)));
        CHECK(((ansIn==in1)||(ansIn==in2)));
        CHECK(((ansPost==post1)||(ansPost==post2)));

    }
    cout << "check first \n";

    CHECK_NOTHROW(cout<<btInt<<endl);
    
}

TEST_CASE("char Binary tree"){
BinaryTree<char> btChar;

    SUBCASE("check the tree is correct"){
    }


    SUBCASE("check override by add_right/add_left"){

    }
    
    CHECK_NOTHROW(cout<<btChar<<endl);
}

TEST_CASE("string Binary tree"){
BinaryTree<string> btString;
    SUBCASE("check -> opperator"){
       
    }
    CHECK_NOTHROW(cout<<btString<<endl);
}