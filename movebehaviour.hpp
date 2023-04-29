
#ifndef MOVE_HPP
#define MOVE_HPP

#include "raylib.h"
#include "ibehaviour.hpp"

namespace game
{
class Agent;

class MoveBehaviour : public IBehaviour
{
public:
    MoveBehaviour();
    ~MoveBehaviour();

    virtual void Update(Agent* agent, float deltaTime);

private:

};
}

#endif // MOVE_HPP