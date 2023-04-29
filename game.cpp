
#include <cstddef>

#include "game.hpp"

namespace game
{
enum targets
{
    R = 0,
    B = 1
};

const int g_window_w = 800;
const int g_window_h = 600;
const int g_fps = 60;
const float g_radius = 25.0;
const float g_deltaTime = 1.0 / g_fps;

Game::Game() : m_score(0)
{
}

Game::~Game()
{
    DeleteVector(m_agents);
    DeleteVector(m_behaviours);
    delete m_player;
}

bool Game::Initialise()
{
    SetTargetFPS(g_fps);
    InitWindow(g_window_w, g_window_h, "first try");
    
    Vector2 startPos = {g_window_w >> 1, g_window_h >> 1};
    m_player = new Agent(startPos, g_radius, VIOLET, 5.0);
    IBehaviour *moveBehaviour = new MoveBehaviour();
    m_player->AddBehaviour(moveBehaviour);
    
    Vector2 topRightCorner = {g_window_w - 40, 20};
    Agent *redEnemy = new Agent(topRightCorner, g_radius, RED, 5.0);
    IBehaviour *seek = new Seek(m_player);
    redEnemy->AddBehaviour(seek);

    Vector2 bottomLeftCorner = {(g_window_w >> 1) - 100, 
                                (g_window_h >> 1) - 100};
    Agent *blueEnemy = new Agent(bottomLeftCorner, g_radius, BLUE, 5.0);
    IBehaviour *flee = new Flee(m_player);
    blueEnemy->AddBehaviour(flee);
    
    m_agents.push_back(redEnemy);
    m_agents.push_back(blueEnemy);

    m_behaviours.push_back(moveBehaviour);
    m_behaviours.push_back(seek);
    m_behaviours.push_back(flee);

    return IsWindowReady();
}

void Game::RunLoop()
{
    while (!WindowShouldClose())
    {
        ProcessInput();
        UpdateGame(g_deltaTime);
        GenerateOutput();
    }
}

void Game::ShutDown()
{
    CloseWindow();
}

void Game::ProcessInput()
{

}

void Game::UpdateGame(float deltaTime)
{
    static double lastUpdateScoreTime = 0;
    DrawText("chase", 280, 10, 20, WHITE);
    DrawText("Blue", 350, 10, 20, BLUE);
    DrawText("and escape", 400, 10, 20, WHITE);
    DrawText("Red", 520, 10, 20, RED);

    m_player->Update(deltaTime);
    for (std::size_t i = 0; i < m_agents.size(); ++i)
    {
        m_agents[i]->Update(deltaTime);
    }

    if ((GetTime() - lastUpdateScoreTime) > 0.3)
    {
        UpdateScore();
        lastUpdateScoreTime = GetTime();
    }

    DrawText(TextFormat("Score: %d", m_score), 10, 10, 20, WHITE);
    DrawText(TextFormat("FPS: %d", GetFPS()), 10, 30, 20, WHITE);   
}

void Game::GenerateOutput()
{
    BeginDrawing();
    ClearBackground(BLACK);
   
    m_player->Draw();
    for (std::size_t i = 0; i < m_agents.size(); ++i)
    {
        m_agents[i]->Draw();
    }
    EndDrawing();
}

template <typename T>
void Game::DeleteVector(std::vector<T *>& vec)
{
    while (vec.size() > 0)
    {
        delete vec.back();
        vec.pop_back();
    }
}

void Game::UpdateScore()
{
    m_score -= CheckCollisionCircles(m_player->GetPosition(), g_radius, 
                m_agents[R]->GetPosition(), g_radius) ? 1 : 0;
    m_score += CheckCollisionCircles(m_player->GetPosition(), g_radius, 
                m_agents[B]->GetPosition(), g_radius) ? 1 : 0;
}

} // game namespace
