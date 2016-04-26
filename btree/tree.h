#ifndef TREE_H
#define TREE_H
#include "node.h"
#include <iostream>
using namespace std;

template<class T>
class tree
{
    public:
        node<T> *root;
        tree() {root = 0;}

        bool find(T data_ ,node<T> **&p){
           p=&root;
            while (*p)
            {   if((*p)->data==data_)return 1;

                p=&((*p)->leaf[((*p)->data < data_)]);
            }
            return 0;
        }

        bool insert (T n){
            node<T> **p;
            find (n,p);
            node<T> *q = new node<T>(n);
            *p=q;
            return true;
        }

        bool inorder (node<T> *p){
            if (!p)return 0;{
            inorder(p->leaf[0]);
            cout<<p->data<<endl;
            inorder(p->leaf[1]);
            }
        }

        node<T>** replace(node<T>** p){
            node<T>** tmp = &(*p)->leaf[1];
            while ( (*tmp)->leaf[0] )
                tmp = &(*tmp)->leaf[0];
            return tmp;
        }

        bool remove (T n){
            node<T> **p;
            node<T> **q;
            if(!find(n,p))return 0;

            bool l =!!(*p)->leaf[0];
            bool r =!!(*p)->leaf[1];

            if(l & r)
            {
                q=replace (p) ;

                (*p)->data=(*q)->data;
                p=q;
                l=!!(*p)->leaf[0];
                r=!!(*p)->leaf[1];
            }

            if(!l & !r){
                delete *p;
                *p=0;
                return 1;
            }
            if((l  &!r ) | (!l & r)){
                node<T> *t =*p;
                *p=((*p)->leaf[r]);
                delete t;
                return 2;
            }
        }

        /*void graph(){

            ofstream dotFile;
            dotFile.open("btree.dot");
            dotFile.clear();
            dotFile<<"Binary tree \n";
            dotFile<<'\n';
            dotFile<<"Graph Tree {\n";
            if (root)
            {
                dotFile<<build(root);
            }
            dotFile<<"}";
            dotFile.close();

        }

        string intToString(int a)
        {
            ostringstream convert;
            convert<<a;
            return convert.str();
        }

        string build(node<T>* a)
        {
            if (a==0)
                return " ";
            string string_="";
            if (a->leaf[0]!=0)
                string_+= intToString(a->data) + "->" + intToString((a->leaf[0])->data) + "; \n";
            if (a->leaf[1]!=0)
                string_+= intToString(a->data) + "->" + intToString((a->leaf[1])->data) + "; \n";
            string_ += build(a->nodes[0]);
            string_ += build(a->nodes[1]);
            return string_;
        };*/

        virtual ~tree() {}
    protected:
    private:
};

#endif // ARBOL_H


