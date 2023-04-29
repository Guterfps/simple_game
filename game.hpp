
#ifndef  GAME_HPP
#define  GAME_HPP

#include <vector>

#include "raylib.h"
#include "agent.hpp"

#include "movebehaviour.hpp"
#include "seek.hpp"
#include "flee.hpp"

namespace game
{
class Game
{
public:
    explicit Game();
    ~Game();
    
    bool Initialise();
    void RunLoop();
    void ShutDown();
    
private:
    void ProcessInput();
    void UpdateGame(float deltaTime);
    void GenerateOutput();
    template <typename T>
    void DeleteVector(std::vector<T *>& vec);
    void UpdateScore();
    
    Agent *m_player;
    std::vector<Agent *> m_agents;
    std::vector<IBehaviour *> m_behaviours;
    int m_score;
};

} // game

#endif // GAME_HPP