#include "SkillSystem.h"

void SkillSystem::getGamemode(Gamemode& gm, Players& p)
{
	gamemode = &gm;
	controlledPlayer = &p;
}

void SkillSystem::setSkillsGamemode()
{
	skill1 = new Frozen(*controlledPlayer, *gamemode);
	skill2 = new PerfectShoot(*controlledPlayer, *gamemode);
	skill3 = new Vortex(*controlledPlayer, *gamemode);
}

void SkillSystem::tickSkills()
{
	skill1->tickPower();
	skill2->tickPower();
	skill3->tickPower();
}
