#pragma once
//Headers
#include "AudioComponent.h"
#include <vector>


class AudioManager{
  public:
    //Constructor
    AudioManager(){}

    void addAudioComponent(AudioComponent* c){
        components.push_back(c);
    }
    void update(){
        for(int i=0; i<components.size();i++){
        components[i]->update();
        }
  }
private:
  std::vector<AudioComponent*> components;
};
