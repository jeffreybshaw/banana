#include <stdio.h>
#include <stdlib.h>
#include <libbanana.h>

int main(int argc, char **argv)
{
	struct banana *banana;

	banana = banana_alloc();
	if (!banana) {
		printf("Cannot allocate banana\n");
		return 1;
	}

	banana_display(banana);

	banana_set_color(banana, BANANA_COLOR_YELLOW);
	banana_set_size(banana, BANANA_SIZE_LARGE);

	banana_display(banana);

	free(banana);

	return 0;
}
