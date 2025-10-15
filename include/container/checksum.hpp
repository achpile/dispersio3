#ifndef __CONTAINER_CHECKSUM
#define __CONTAINER_CHECKSUM


namespace ach
{
	struct Checksum
	{
		json_t *data;


		 Checksum();
		~Checksum();

		void load();
		void save();

		void check(const char *path);
		void store(const char *path);
	};
}

#endif
