#include "SFC/BezierCurve.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <cmath>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	settings.attributeFlags = sf::ContextSettings::Debug;

	sf::RenderWindow app(sf::VideoMode(600, 600), "app", sf::Style::Default, settings);
	app.setVerticalSyncEnabled(true);

	sf::Clock timer;

	sfc::BezierCubicCurve curve1(
	{200, 50}, {350, 500},
	{50, 50}, {50, 550},
	sfc::DEBUG);
	curve1.setNormalizedLengthLimit(1.f);
	curve1.setPointCount(2048);
	curve1.update();

	sfc::BezierCubicCurve curve2(
	{350, 500}, {200, 50},
	{500, 475}, {400, 50},
	sfc::DEBUG);
	curve2.setNormalizedLengthLimit(1.f);
	curve2.setPointCount(2048);
	curve2.update();

	auto iterations = 0u;
	for(;app.isOpen(); ++iterations)
	{
		for(sf::Event ev; app.pollEvent(ev);)
		{
			if(ev.type == sf::Event::Closed)
				app.close();
		}

		app.clear({20, 20, 20});

		app.draw(curve2);
		app.draw(curve1);

		app.display();
	}

	std::cout << timer.getElapsedTime().asSeconds() << std::endl << (iterations / timer.getElapsedTime().asSeconds()) << "FPS" << std::endl;
	return 0;
}
