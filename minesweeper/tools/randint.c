#include <fcntl.h>
#include <unistd.h>

#include "../all.h"

#define ABS(nb) ((nb < 0) ? -nb : nb)

int randint(t_map *map)
{
	int fd;
	int rand;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, &rand, sizeof(int));
	close(fd);
	return (ABS(rand) % (map->x * map->y));
}
