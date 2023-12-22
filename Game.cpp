#include "Game.h"
#include <iostream>

using namespace std;

void Game::InitializeRooms()
{

}

void Game::WelcomePlayer()
{
    cout << "Welcome to Text Adventure" << endl << endl;
    cout << "What is your name: ";

    string name;

    cin >> name;
    m_player.SetName(name);

    cout << endl << "Hello, " << m_player.GetName() << endl;

    return;
}

void Game::GivePlayerOptions()
{
    cout << "What would you like to do? (Enter a corresponding number)" << endl << endl;
    cout << "Quit: 1" << endl << endl;
}

void Game::GetPlayerInput(std::string& playerInput)
{
    cin >> playerInput;
}

PlayerOptions Game::EvaluateInput(std::string& playerInput)
{
    PlayerOptions choosenOption = PlayerOptions::None;

    if (playerInput.compare("1") == 0)
    {
        cout << "You have choosen to quit" << endl << endl;
        choosenOption = PlayerOptions::Quit;
    }
    else
    {
        cout << "I do not recognize that option. Please try again." << endl << endl;
    }

    return choosenOption;
}

void Game::RunGame()
{
    WelcomePlayer();

    bool shouldEnd = false;

    while (shouldEnd == false)
    {
        GivePlayerOptions();

        string playerInput;
        GetPlayerInput(playerInput);

        shouldEnd = EvaluateInput(playerInput) == PlayerOptions::Quit;
    }
}