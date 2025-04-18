#ifndef __CONTAINER_SETTINGS
#define __CONTAINER_SETTINGS


namespace ach
{
	struct Settings
	{
		json_t *data;


		 Settings();
		~Settings();


		bool isFullscreen();
		bool isSmooth();

		const char   *getLanguage();
		const char   *getTheme();

		int           getVolumeSound();
		int           getVolumeMusic();

		sf::VideoMode getWindowMode();
		sf::Uint32    getWindowStyle();
		sf::Vector2i  getWindowPosition();

		void          setWindowSize(sf::Vector2u size);

		sf::Keyboard::Key getKeyCode(ach::ControlAction action);
		ach::JoystickCode getJoyCode(ach::ControlAction action);
		void              setKeyCode(ach::ControlAction action, sf::Keyboard::Key code);
		void              setJoyCode(ach::ControlAction action, ach::JoystickCode code);
	};
}

#endif
