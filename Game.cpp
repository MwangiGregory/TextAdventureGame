#include "Game.h"
#include <iostream>

using namespace std;

void Game::InitializeRooms()
{
    // Room 0 heads North to Room 1
    m_rooms[0].AddRoom(Room::JoiningDirections::North, &(m_rooms[1]));

    // Room 1 heads East to Room 2, South to Room 0 and West to Room 3
    m_rooms[1].AddRoom(Room::JoiningDirections::East, &(m_rooms[2]));
    m_rooms[1].AddRoom(Room::JoiningDirections::South, &(m_rooms[0]));
    m_rooms[1].AddRoom(Room::JoiningDirections::West, &(m_rooms[3]));

    // Room 2 heads West to Room 1
    m_rooms[2].AddRoom(Room::JoiningDirections::West, &(m_rooms[1]));

    // Room 3 heads East to Room 1
    m_rooms[3].AddRoom(Room::JoiningDirections::East, &(m_rooms[1]));

    m_player.SetCurrentRoom(&(m_rooms[0]));

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
    InitializeRooms();

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