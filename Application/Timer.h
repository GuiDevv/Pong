#include <SFML/System/Clock.hpp>

using namespace sf;

class Timer 
{
	Clock clock;
	float time;
public:
	void start(float time) {
		this->time = time;
		clock.restart();
	}
	float elapsedTimer() { return clock.getElapsedTime().asSeconds(); }
	bool hasEnded() { return clock.getElapsedTime().asSeconds() > time; }
};