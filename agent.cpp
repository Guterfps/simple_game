
#include <iterator>
#include <iostream>

#include "agent.hpp"
#include "ibehaviour.hpp"

#include "raymath.h"

namespace game
{
Agent::Agent(const Vector2& pos, float radius, Color colour, float maxSpeed) :
            m_radius(radius), m_color(colour), m_maxSpeed(maxSpeed), 
            m_position(pos)
{
    Vector2 acc = {0.0, 0.0};
    Vector2 vel = {0.0, 0.0};
    
    SetAcceleration(acc);
    SetVelocity(vel);
}

Agent::~Agent()
{
}

void Agent::Update(float deltaTime)
{
    std::list<IBehaviour*>::iterator it = m_behaviours.begin();

    for (; it != m_behaviours.end(); ++it)
    {
        (*it)->Update(this, deltaTime);
    }

    m_velocity.x += m_acceleration.x;
    m_velocity.y += m_acceleration.y;

    if (Vector2Length(m_velocity) > m_maxSpeed)
    {
        m_velocity = Vector2Scale(Vector2Normalize(m_velocity), m_maxSpeed);
    }

    m_position.x += m_velocity.x;
    m_position.y += m_velocity.y;

    m_position.x = (m_position.x < 0.0) ? GetScreenWidth() : m_position.x;
    m_position.x = (m_position.x > GetScreenWidth()) ? 0.0 : m_position.x;
    m_position.y = (m_position.y < 0.0) ? GetScreenHeight() : m_position.y;
    m_position.y = (m_position.y > GetScreenHeight()) ? 0.0 : m_position.y;

    m_acceleration.x = 0.0;
    m_acceleration.y = 0.0;
}

void Agent::Draw()
{
    DrawCircleV(m_position, m_radius, m_color);
}

void Agent::SetPosition(const Vector2& pos)
{
    m_position = pos;
}

Vector2 Agent::GetPosition() const
{
    return m_position;
}

void Agent::SetAcceleration(const Vector2& accel)
{
    m_acceleration = accel;
}

Vector2 Agent::GetAcceleration() const
{
    return m_acceleration;
}

void Agent::SetVelocity(const Vector2& vel)
{
    m_velocity = vel;
}

Vector2 Agent::GetVelocity() const
{
    return m_velocity;
}

void Agent::AddBehaviour(IBehaviour *behaviour)
{
    m_behaviours.push_back(behaviour);
}

void Agent::SetMaxSpeed(float speed)
{
    m_maxSpeed = speed;
}

float Agent::GetMaxSpeed() const
{
    return m_maxSpeed;
}

} //game
