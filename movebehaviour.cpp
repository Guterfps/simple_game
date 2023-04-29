#include <iostream> 
#include "movebehaviour.hpp"
#include "agent.hpp"
#include "raymath.h"

namespace game
{
const float g_step = 1.0;

enum move
{
    LEFT = KEY_A,
    RIGHT = KEY_D,
    UP = KEY_W,
    DOWN = KEY_S
};

MoveBehaviour::MoveBehaviour()
{

}

MoveBehaviour::~MoveBehaviour()
{

}

void MoveBehaviour::Update(Agent *agent, float deltaTime)
{
    Vector2 nextMove = agent->GetPosition();
    nextMove.x -= IsKeyDown(LEFT) ? g_step : 0;
    nextMove.x += IsKeyDown(RIGHT) ? g_step : 0;
    nextMove.y -= IsKeyDown(UP) ? g_step : 0;
    nextMove.y += IsKeyDown(DOWN) ? g_step : 0;
    
    Vector2 direction = Vector2Subtract(nextMove, agent->GetPosition());
    agent->SetAcceleration(Vector2Scale(Vector2Normalize(direction), 
                                        agent->GetMaxSpeed() *  deltaTime));
}
} // game