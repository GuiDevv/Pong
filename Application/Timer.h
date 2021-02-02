#include <SFML/System/Clock.hpp>
#ifndef _timer
#define _timer

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

#endif // !_timer