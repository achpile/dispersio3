#ifndef __FRAMEWORK_RANDOM_SHUFFLE_INL
#define __FRAMEWORK_RANDOM_SHUFFLE_INL


/***********************************************************************
     * random_shuffle

***********************************************************************/
template <typename T>
void random_shuffle(std::vector<T> *list, unsigned int offset, unsigned int count)
{
	if (!count)
		return;

	if (offset + count > list->size())
		return;


	int a;
	int b;
	T   k;

	for (unsigned int i = 0; i < count * 2; i++)
	{
		a = rand() % (count) + offset;
		b = rand() % (count) + offset;

		if (a == b)
			continue;

		k          = (*list)[a];
		(*list)[a] = (*list)[b];
		(*list)[b] = k;
	}
}



/***********************************************************************
     * random_shuffle

***********************************************************************/
template <typename T>
void random_shuffle(std::vector<T> *list)
{
	random_shuffle(list, 0, list->size());
}

#endif
