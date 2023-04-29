
#include "seek.hpp"
#include "agent.hpp"
#include "raymath.h"

namespace game
{
Seek::Seek(Agent* agent) : m_target(agent)
{
}

Seek::~Seek()
{
}

void Seek::Update(Agent *agent,  float deltaTime)
{
    Vector2 direction = Vector2Subtract(m_target->GetPosition(), 
                                        agent->GetPosition());
    agent->SetAcceleration(Vector2Scale(Vector2Normalize(direction), 
                                        agent->GetMaxSpeed() * deltaTime));
}
} // game