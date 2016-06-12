
#include <string>
#include <memory>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>


static std::shared_ptr<sf::Window> CreateWindowS()
{
	auto    window = std::make_shared<sf::Window>(
			sf::VideoMode(800, 600),
			L"SimTaiwan",
			sf::Style::Default,
			sf::ContextSettings(24) );

	return window;
}

int main()
{
	auto    window = CreateWindowS();

	window->setActive();

	while ( window->isOpen() )
	{
		sf::Event event;

		while ( window->pollEvent(event) )
		{
			switch ( event.type )
			{
				case sf::Event::Closed:

					window->close();
					break;

				case sf::Event::KeyPressed:

					if ( event.key.code == sf::Keyboard::Escape )
					{
						window->close();
					}
					break;

				case sf::Event::Resized:

					//glViewport(0, 0, event.size.width, event.size.height);
					break;

				default:
					break;
			}
		}

		window->display();
	}

	return EXIT_SUCCESS;
}
