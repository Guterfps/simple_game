
#ifndef SEEK_HPP
#define SEEK_HPP

#include "raylib.h"
#include "ibehaviour.hpp"

namespace game
{
class Agent;

class Seek : public IBehaviour
{
public:
    Seek(Agent *agent);
    virtual ~Seek();

    virtual void Update(Agent *agent, float deltaTime);

private:
    Agent *m_target;
};
}

#endif // SEEK_HPP