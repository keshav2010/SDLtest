#include<iostream>
#include "PlayState.h"
using namespace std;
const string PlayState::playID="PLAY";

string PlayState::getStateID() const{
    return playID;
}
void PlayState::update()
{

}
void PlayState::render()
{

}
bool PlayState::onEnter()
{
    cout<<"enter playstate\n";
    return true;
}
bool PlayState::onExit()
{
    cout<<"exit playstate\n";
    return true;
}
