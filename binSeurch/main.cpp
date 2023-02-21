#include "Header.h"

int main() {
    Tree tree;
    tree.AddElement(tree._root, 2);
    tree.AddElement(tree._root, 6);
    tree.AddElement(tree._root, 8);
    tree.AddElement(tree._root, 4);
    tree.AddElement(tree._root, 1);
    tree.AddElement(tree._root, -1);

//    tree.PrintTree(tree._root);
    printf("        %d   \n", tree._root->_data);
    printf("    %d\n", tree._root->_l->_data);
    printf("%d", tree._root->_l->_l->_data);
    printf("         %d\n", tree._root->_r->_data);
    printf("       %d  ", tree._root->_r->_l->_data);
    printf("     %d\n", tree._root->_r->_r->_data);
}
