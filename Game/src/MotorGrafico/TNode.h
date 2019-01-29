#include "TEntity.h"
#include <vector>
class TNode
{
    private: 
        TEntity*            entity;
        std::vector<TNode*> child;
        TNode*              father;
    public:
        TNode(){}
        ~TNode(){}
        
        int addChild(TNode* n);
        int remChild(TNode*n);

        //*********
        //GET & SET
        //*********

        bool setEntity(TEntity*);
        TEntity *getEntity();
        TNode *getFather();
        
        void draw(); 
};