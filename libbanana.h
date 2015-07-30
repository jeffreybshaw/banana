#ifndef _BANANA_H
#define _BANANA_H

struct banana;

enum banana_color {
	BANANA_COLOR_NONE,
	BANANA_COLOR_GREEN,
	BANANA_COLOR_YELLOW,
	BANANA_COLOR_BROWN,
	BANANA_COLOR_MAX,
};

enum banana_size {
	BANANA_SIZE_NONE,
	BANANA_SIZE_SMALL,
	BANANA_SIZE_MEDIUM,
	BANANA_SIZE_LARGE,
	BANANA_SIZE_MAX,
};

const char *banana_color_to_str(enum banana_color color);
const char *banana_size_to_str(enum banana_size size);

struct banana *banana_alloc(void);
void banana_init(struct banana *banana);
int banana_set_color(struct banana *banana, enum banana_color color);
int banana_set_size(struct banana *banana, enum banana_size size);

void banana_display(struct banana *banana);

#endif /* _BANANA_H */
