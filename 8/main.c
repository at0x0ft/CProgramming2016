#include <stdio.h>

int x = 1;	/* グローバル変数 */

void func(void);

int main(void)
{
	func();
	return 0;
}
