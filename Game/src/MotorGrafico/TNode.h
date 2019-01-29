#include "TEntidad.h"
#include <vector>
class TNode
{
    private: 
        TEntity*            entity;
        std::vector<TNode*> son;
        TNode*              father;
    public:
        TNode(){}
        ~TNode(){}
        
        int AddSon(TNode* n);
        int remSon(TNode*n);

        //*********
        //GET & SET
        //*********

        bool setEntity(TEntity*);
        TEntity *getEntity();
        TNode *getFather();
        void draw(); 
}