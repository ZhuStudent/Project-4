//BSTList.cpp
#include "BSTNode.hpp"
#include <iostream>
using namespace std;

BSTList::BSTList()
{
    head = nullptr;
}

void BSTList::deleteNode(int num)
{
    BSTNode *nodePtr;
    BSTNode *previousNode = nullptr;
    
    if(!head)
    return;
    if(head -> data == num)
    {
        nodePtr = head -> next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;
        while(nodePtr != nullptr && nodePtr -> data != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr -> next;
        }
        if(nodePtr)
        {
            previousNode -> next = nodePtr -> next;
            delete nodePtr;
        }
    }
}

void BSTList::insertNode(int num)
{
    BSTNode *newNode;
    BSTNode *nodePtr;
    BSTNode *previousNode;
    
    newNode = new BSTNode;    
    newNode->data = num;
    newNode->next = nullptr;
    
    if(!head)                   
    {
        head = newNode;
    }
    else
    {                       
        nodePtr = head;
        previousNode = nullptr;
        
        while(nodePtr->data < num && nodePtr != nullptr)
        {  
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }                                   

        if(!previousNode)        
        {
            head = newNode;
            newNode->next = nodePtr;        
        }
        else
        {  
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}
