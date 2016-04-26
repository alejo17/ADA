#ifndef NODE_H
#define NODE_H

template<class T>
class node
{
    public:
        node(){
            leaf [0]=0;
            leaf [1]=0;
        }
        node (T _data){
            data=_data;
            leaf[0]=0;
            leaf[1]=0;
        }
        T data ;
        node * leaf [2];
        virtual ~node(){}
    protected:
    private:
};

#endif // NODE_H
