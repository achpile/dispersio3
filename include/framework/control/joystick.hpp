#ifndef __FRAMEWORK_CONTROL_JOYSTICK
#define __FRAMEWORK_CONTROL_JOYSTICK


namespace ach
{
	enum JoystickCode
	{
		jcUnknown    = -1,
		jcAxisXminus =  0,
		jcAxisXplus,
		jcAxisYminus,
		jcAxisYplus,
		jcAxisZminus,
		jcAxisZplus,
		jcAxisRminus,
		jcAxisRplus,
		jcAxisUminus,
		jcAxisUplus,
		jcAxisVminus,
		jcAxisVplus,
		jcAxisPovXminus,
		jcAxisPovXplus,
		jcAxisPovYminus,
		jcAxisPovYplus,
		jcButton1,
		jcButton2,
		jcButton3,
		jcButton4,
		jcButton5,
		jcButton6,
		jcButton7,
		jcButton8,
		jcButton9,
		jcButton10,
		jcButton11,
		jcButton12,
		jcButton13,
		jcButton14,
		jcButton15,
		jcButton16,
		jcButton17,
		jcButton18,
		jcButton19,
		jcButton20,
		jcButton21,
		jcButton22,
		jcButton23,
		jcButton24,
		jcButton25,
		jcButton26,
		jcButton27,
		jcButton28,
		jcButton29,
		jcButton30,
		jcButton31,
		jcButton32,
		jcCount
	};


	struct Joystick
	{
		 Joystick();
		~Joystick();

		void update();

		bool check(ach::JoystickCode code);

		bool axis(sf::Joystick::Axis axis, bool plus);
		bool button(unsigned int button);
	};
}

#endif
