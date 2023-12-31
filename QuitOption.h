#pragma once
#include <iostream>
#include "Option.h"
#include "PlayerOptions.h"

class QuitOption : public Option
{
private:
	bool m_shouldQuit;

public:
	QuitOption(const std::string& outputText)
		: Option(PlayerOptions::Quit, outputText)
	{
	}

	bool ShouldQuit() const { return m_shouldQuit; }
	virtual bool Evaluate(const std::string& optionText, Player& player);
};