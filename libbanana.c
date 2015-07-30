#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <libbanana.h>

struct banana {
	enum banana_color color;
	enum banana_size size;
};

struct banana *banana_alloc(void)
{
	struct banana *banana;

	banana = calloc(1, sizeof(struct banana));
	banana_init(banana);

	return banana;
}

void banana_init(struct banana *banana)
{
	if (banana) {
		banana_set_color(banana, BANANA_COLOR_GREEN);
		banana_set_size(banana, BANANA_SIZE_SMALL);
	}
}

int banana_set_color(struct banana *banana, enum banana_color color)
{
	int rc = 0;

	if (banana && color < BANANA_COLOR_MAX)
		banana->color = color;
	else
		rc = -EINVAL;

	return rc;
}

int banana_set_size(struct banana *banana, enum banana_size size)
{
	int rc = 0;

	if (banana && size < BANANA_SIZE_MAX)
		banana->size = size;
	else
		rc = -EINVAL;

	return rc;
}

void banana_display(struct banana *banana)
{
	if (banana) {
		if (banana->size > BANANA_SIZE_NONE &&
		    banana->size < BANANA_SIZE_MAX)
			printf("The %s banana is %s in size\n",
			       banana_color_to_str(banana->color),
			       banana_size_to_str(banana->size));
		else
			printf("The %s banana is of unknown size\n",
			       banana_color_to_str(banana->color));
	}
}

const char *banana_size_strings[] = {
	[BANANA_SIZE_NONE] = "",
	[BANANA_SIZE_SMALL] = "small",
	[BANANA_SIZE_MEDIUM] = "medium",
	[BANANA_SIZE_LARGE] = "large",
};

const char *banana_color_strings[] = {
	[BANANA_COLOR_NONE] = "",
	[BANANA_COLOR_GREEN] = "green",
	[BANANA_COLOR_YELLOW] = "yellow",
	[BANANA_COLOR_BROWN] = "brown",
};

const char *banana_color_to_str(enum banana_color color)
{
	if (color < BANANA_COLOR_MAX)
		return banana_color_strings[color];
	else
		return banana_color_strings[BANANA_COLOR_NONE];
}

const char *banana_size_to_str(enum banana_size size)
{
	if (size < BANANA_SIZE_MAX)
		return banana_size_strings[size];
	else
		return banana_size_strings[BANANA_SIZE_NONE];
}
