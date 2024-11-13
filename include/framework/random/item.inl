#ifndef __FRAMEWORK_RANDOM_ITEM_INL
#define __FRAMEWORK_RANDOM_ITEM_INL


/***********************************************************************
     * RandomItem
     * constructor

***********************************************************************/
template <typename T>
ach::RandomItem<T>::RandomItem(T _value, int _weight)
{
	value  = _value;
	weight = _weight;
	offset = 0;
}



/***********************************************************************
     * RandomItem
     * destructor

***********************************************************************/
template <typename T>
ach::RandomItem<T>::~RandomItem()
{
}



/***********************************************************************
     * RandomItem
     * update

***********************************************************************/
template <typename T>
void ach::RandomItem<T>::update(int _offset)
{
	offset = _offset;
}

#endif
