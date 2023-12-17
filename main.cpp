#include <iostream>
#include "vector.h"
#include "stackVec.h"
#include "OLL.h"
#include "DLL.h"
#include "BST.h"




int main() {
    Tree<int> myTree;
    int a[10] = {2,5,12,1,4,0,6,7,8,10};

    for (int key: a)
        myTree.insertNode(key);

    myTree.inorderWalk(myTree.getRoot());

    return 0;

    return 0;
}
