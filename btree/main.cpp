#include <iostream>
#include "tree.h"
using namespace std;

int main()
{
    tree<int> tree_;
    tree_.insert (124);
    tree_.insert (965);
    tree_.insert (612);
    tree_.insert (54);
    tree_.insert (228);
    tree_.insert (5345);
    tree_.insert (11);
    tree_.inorder(tree_.root);

    tree_.remove(228);
    cout<<"---"<<endl;
    tree_.inorder(tree_.root);

    return 0;
}
