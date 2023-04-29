
#ifndef FLEE_HPP
#define FLEE_HPP

#include "raylib.h"
#include "ibehaviour.hpp"

namespace game
{
class Agent;

class Flee : public IBehaviour
{
public:
    Flee(Agent *target);
    virtual ~Flee();

    virtual void Update(Agent *agent, float deltaTime);

private:
    Agent *m_target;
};
}

#endif // FLEE_HPP