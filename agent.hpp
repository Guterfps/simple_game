
#ifndef AGENT_HPP
#define AGENT_HPP

#include <list>

#include "raylib.h"

namespace game
{
class IBehaviour;

class Agent
{
public:
    Agent(const Vector2& pos,
         float radius = 5.0, 
         Color colour = BLUE,
         float maxSpeed = 50.0);
    virtual ~Agent();
    
    virtual void Update(float deltaTime);
    virtual void Draw();
    
    void SetPosition(const Vector2& pos);
    Vector2 GetPosition() const;
    void SetAcceleration(const Vector2& accel);
    Vector2 GetAcceleration() const;
    void SetVelocity(const Vector2& vel);
    Vector2 GetVelocity() const;
    void SetMaxSpeed(float speed);
    float GetMaxSpeed() const;
    void AddBehaviour(IBehaviour *behaviour);
    
private:
    float m_radius;
    Color m_color;
    float m_maxSpeed;
    Vector2 m_position;
    Vector2 m_acceleration;
    Vector2 m_velocity;
    std::list<IBehaviour *> m_behaviours;    
};
} // game

#endif // AGENT_HPP
