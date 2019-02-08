#include "TNode.h"
#include <iostream>
#include "TEntity.h"
TNode::~TNode()
{

}

bool TNode::addChild(TNode* n)
{
    //Add child to the end of the vector or throws excepción 'bad_alloc'
    //and ends the execution
    if(n->getFather()==this)
    {
        std::cout<<"Meto en el padre :"<<getId()<<" el hijo que es : "<<n->getId()<<std::endl;
        child.push_back(n);
    }
    return true;
}

//Takes and deletes the child from the vector
bool TNode::remChild(TNode* n)
{
    for(unsigned int i=0; i<child.size();i++)
    {
        if(n == child[i])
        {   
            //erase returns and iterator to de next position of the deleted
            //node or an exception if its out of range
            delete child[i]; //release memory
            child.erase(child.begin()+i);
            
            child.shrink_to_fit(); //memory adapted to the vector new size
            return true;
        }
    }
    return false;
}

//Pops the child from the vector but doesnt delte it
bool TNode::popChild(TNode* n)
{
    for(unsigned int i=0; i<child.size();i++)
    {
        if(n == child[i])
        {   
            //erase returns and iterator to de next position of the deleted
            //node or an exception if its out of range
            child.erase(child.begin()+i);
            child.shrink_to_fit(); //memory adapted to the vector new size
            return true;
        }
    }
    return false;
}

TNode* TNode::searchChild(unsigned int n)
{
    if(n>0 && n<=child.size())
    {
        return child[n];
    }
    return nullptr;
}

//Deletes all the branch in preorder except for the node that calls the method
void TNode::killBranch()
{
    for(unsigned int i=0; i<child.size();i++)
    {
        if(child[i]!=nullptr)
        {
            child[i]->killBranch();
        }
    }
    delete this;
    std::cout<<"Me he muerto y soy : "<<getId()<<std::endl;
    child.clear();
    child.shrink_to_fit();

}

//Draws the tree of nodes in inorder
void TNode::draw()
{
    if(entity)
    {
        std::cout<<getId()<<std::ends;
        entity->beginDraw();
    }
    for(unsigned int i = 0; i<child.size(); i++)
        {
            child[i]->draw();
        }
    if(entity)
    {
        entity->endDraw();
    }
}