#ifndef __FRAMEWORK_RANDOM_LIST
#define __FRAMEWORK_RANDOM_LIST


namespace ach
{
	template <typename T>
	struct RandomList
	{
		std::vector<ach::RandomItem<T>*> list;

		int sum;


		 RandomList();
		~RandomList();

		void add(T value, int weight);
		void clear();
		void update();

		T get();
	};
}

#endif
