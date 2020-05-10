#include <stdio.h>
void HanoiTowerMove(int num, char from, char by, char to) {
	if (num == 1)
		printf("원반 %d를 %c 에서 %c\n",num, from, to);
	else {
		HanoiTowerMove(num - 1, from, to, by);
		printf("원반 %d를 %c 에서 %c\n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}
//int main(void) {
//	HanoiTowerMove(2, 'A', 'B', 'C');
//	return 0;
//}