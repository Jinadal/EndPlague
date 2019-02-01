#include "TNode.h"

bool TNode::addChild(TNode* n)
{
    //Add child to the end of the vector or throws excepción 'bad_alloc'
    //and ends the execution
    child.push_back(n);
    return true;
}

bool TNode::remChild(TNode* n)
{
    for(unsigned int i=0; i<child.size();i++)
    {
        if(n == child[i])
        {   
            //erase returns and iterator to de next position of the deleted
            //node or an exception if its out of range
            child.erase(child.begin()+i);
            delete child[i]; //release memory
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

void TNode::draw()
{
    if(entity)
    {
        entity->beginDraw();
            for(unsigned int i = 0; i<child.size(); i++)
            {
                child[i]->draw();
            }
        entity->endDraw();
    }
}