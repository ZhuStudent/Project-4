//D.Flemmings
//Project 4
#ifndef BSTNode_hpp
#define BSTNode_hpp

class BSTList
{
    private:
    struct BSTNode
    {
        int data;
        struct BSTNode *next;
    };
    BSTNode *head;
    
    public:
    BSTList();
    void insertNode(int);
    void deleteNode(int);
};
#endif
