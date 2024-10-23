#pragma once

#include <string>

class Player {

private:
	std::string name;
	char symbol;

public:
	Player(const std::string& name, char symbol);

	//Getters
	std::string getName() const;
	char getSymbol() const;
};

