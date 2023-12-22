#pragma once

#include "Player.h"
#include "PlayerOptions.h"
#include "Room.h"

class Game
{
private:
	static const unsigned int m_numOfRooms = 4;
	Room rooms[m_numOfRooms];

	Player m_player;

	void InitializeRooms();
	void WelcomePlayer();

	void GivePlayerOptions();

	void GetPlayerInput(std::string& playerInput);

	PlayerOptions EvaluateInput(std::string& playerInput);

public:
	void RunGame();
};