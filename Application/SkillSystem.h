#pragma once
#include "PlayersSkills.h"

class SkillSystem
{
public:

	class Gamemode* gamemode;
	class PlayersSkills* skill1, * skill2, * skill3;

	void getGamemode(Gamemode& gm);
	void setSkillsGamemode(Players &p);
	void tickSkills();
};

