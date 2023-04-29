
#include "flee.hpp"
#include "agent.hpp"
#include "raymath.h"

namespace game
{
Flee::Flee(Agent* agent) : m_target(agent)
{}

Flee::~Flee()
{}

void Flee::Update(Agent *agent, float deltaTime)
{
    float distance = Vector2Distance(m_target->GetPosition(), 
                                    agent->GetPosition());
    if (distance < 150.0f)
    {
        Vector2 direction = Vector2Subtract(agent->GetPosition(), 
                                            m_target->GetPosition());
        agent->SetAcceleration(Vector2Scale(Vector2Normalize(direction), 
                                        agent->GetMaxSpeed() * deltaTime));
    }
    else
    {
        Vector2 accel = {0.0f, 0.0f};
        accel.x = agent->GetAcceleration().x - agent->GetVelocity().x * deltaTime;
        accel.y = agent->GetAcceleration().y - agent->GetVelocity().y * deltaTime;

        agent->SetAcceleration(accel);
    }
}
} //game