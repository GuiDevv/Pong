#include "SkillSystem.h"

void SkillSystem::getGamemode(Gamemode& gm)
{
	gamemode = &gm;
}

void SkillSystem::setSkillsGamemode()
{
	skill1 = new Frozen();
	skill2 = new PerfectShoot();
	skill3 = new Vortex();
	skill1->gm = gamemode;
	skill2->gm = gamemode;
	skill3->gm = gamemode;
}

void SkillSystem::tickSkills()
{
	skill1->tickPower();
	skill2->tickPower();
	skill3->tickPower();
}
