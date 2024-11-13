#ifndef __FRAMEWORK_RANDOM_LIST_INL
#define __FRAMEWORK_RANDOM_LIST_INL


/***********************************************************************
     * RandomList
     * constructor

***********************************************************************/
template <typename T>
ach::RandomList<T>::RandomList()
{
}



/***********************************************************************
     * RandomList
     * destructor

***********************************************************************/
template <typename T>
ach::RandomList<T>::~RandomList()
{
	clear();
}



/***********************************************************************
     * RandomList
     * add

***********************************************************************/
template <typename T>
void ach::RandomList<T>::add(T value, int weight)
{
	list.push_back(new ach::RandomItem<T>(value, weight));
	update();
}



/***********************************************************************
     * RandomList
     * clear

***********************************************************************/
template <typename T>
void ach::RandomList<T>::clear()
{
	list_delete(list);
}



/***********************************************************************
     * RandomList
     * update

***********************************************************************/
template <typename T>
void ach::RandomList<T>::update()
{
	sum = 0;

	list_foreach(list)
	{
		list[i]->update(sum);
		sum += list[i]->weight;
	}
}



/***********************************************************************
     * RandomList
     * get

***********************************************************************/
template <typename T>
T ach::RandomList<T>::get()
{
	int r = rand() % sum;


	list_foreach(list)
		if (list[i]->offset <= r && r < list[i]->offset + list[i]->weight)
			return list[i]->value;


	if (!list.size())
		return NULL;
	else
		return list[0]->value;
}

#endif
