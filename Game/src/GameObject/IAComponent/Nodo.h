#pragma once
#include <vector>

class Nodo{


    public:

        Nodo(){}
        virtual ~Nodo(){}

        std::vector<Nodo*> children;

        
        virtual bool run();
        void addChild(Nodo* child){
            children.push_back(child);
        }


};

class Selector : public Nodo{

    public:

    Selector():Nodo(){}
    virtual ~Selector(){}
    
    bool run() override;

};

class Secuencia : public Nodo{

    public:

    Secuencia():Nodo(){}
    virtual ~Secuencia(){}

    bool run() override;

};