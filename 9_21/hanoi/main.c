#include "hanoi.h"

int main(void)
{
	HANOI hanoi[3] = {{{3, 2, 1}, 3}, {}, {}};

	hanoi_display(hanoi);

	hanoi_play(hanoi, 0, 1, 2, 3);

	return 0;
}
