#include <iostream>
using std::cout;
using std::endl;

#include "BinaryTree.h"

typedef std::string ItemType;
typedef void (*FunctionType)(ItemType& anItem);

void PrintNode(ItemType& i) { cout << i << endl; };

int main(int argc, char** argv)
{
	BinaryTree<ItemType, FunctionType> TD("D");
	TD.attachLeft("H");
	TD.attachRight("I");
    BinaryTree<ItemType, FunctionType> TE("E");
    BinaryTree<ItemType, FunctionType> TF("F");
    BinaryTree<ItemType, FunctionType> TG("G");
    TG.attachLeft("J");
    BinaryTree<ItemType, FunctionType> T1("B", TD, TE);
    BinaryTree<ItemType, FunctionType> T2("C", TF, TG);

    BinaryTree<ItemType, FunctionType> T3("A");
    T3.attachLeftSubtree(T1);
    T3.attachRightSubtree(T2);
    std::cout << "Post-Order: " << std::endl;
    T3.postorderTraverse(&PrintNode);
    std::cout << std::endl << "Pre-Order: " << std::endl;
    T3.preorderTraverse(&PrintNode);
    std::cout << std::endl << "In-Order: " << std::endl;
    T3.inorderTraverse(&PrintNode);

    // now T1 and T2 are no longer trees, but empty objects

    return 0;
};
