#include "utils.hpp"

void gotoxy(const int x, const int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}
