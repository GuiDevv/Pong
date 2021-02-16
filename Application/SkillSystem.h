#pragma once
#include "Skills.h"
#include <vector>

class SkillSystem
{
public:

	class Gamemode* gamemode;
	class Skills* skill1, * skill2, * skill3;
	class Players* controlledPlayer;

	void getGamemode(Gamemode& gm, Players& p);
	void setSkillsGamemode();
	void tickSkills();
};

