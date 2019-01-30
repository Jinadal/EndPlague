#include "TEntity.h"
#include <vector>
class TNode
{
    private: 
        TEntity*            entity;
        std::vector<TNode*> child;
        TNode*              father;
    public:
        //Constructors
        TNode();                                                //Node Root
        TNode(TNode* f) : father(f) {}                          //Node no entity
        TNode(TNode* f, TEntity* e) : father(f), entity(e) {}
        ~TNode(){}
        
        bool addChild(TNode* n);
        bool remChild(TNode*n);
        TNode* searchChild(unsigned int n);
        //*********
        //GET & SET
        //*********

        void setEntity(TEntity* e){ entity = e;};
        TEntity *getEntity(){ return entity;};
        TNode *getFather(){ return father;};
        
        void draw(); 
};