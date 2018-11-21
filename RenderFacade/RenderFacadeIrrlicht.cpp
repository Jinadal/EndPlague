int RenderFacadeIrrlicht::addNode(){
    scene::ISceneNode * node = smgr->addSphereSceneNode();
    if (node)
    {
        return 0;
    }else{
        retrun 1;
    }
}