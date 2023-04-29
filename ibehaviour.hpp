
#ifndef IBEHAVIOUR_HPP
#define IBEHAVIOUR_HPP

#include "raylib.h"

namespace game
{
class Agent;

class IBehaviour
{
public:
    IBehaviour() {}
    virtual ~IBehaviour() {}
    
    virtual void Update(Agent *agent, float deltaTime) =0;
};
} // game

#endif // IBEHAVIOUR_HPP
