#ifndef __FRAMEWORK_CONTROL_KEY
#define __FRAMEWORK_CONTROL_KEY


namespace ach
{
	struct ControlKey
	{
		sf::Keyboard::Key code;

		bool state;
		bool pressed;
		bool released;


		 ControlKey();
		~ControlKey();

		void update();
		void reset();
	};
}

#endif
