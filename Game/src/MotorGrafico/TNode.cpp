#include "TNode.h"

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