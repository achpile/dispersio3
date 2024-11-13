#ifndef __FRAMEWORK_RANDOM_ITEM
#define __FRAMEWORK_RANDOM_ITEM


namespace ach
{
	template <typename T>
	struct RandomItem
	{
		T   value;
		int weight;
		int offset;


		 RandomItem(T _value, int _weight);
		~RandomItem();

		void update(int _offset);
	};
}

#endif
