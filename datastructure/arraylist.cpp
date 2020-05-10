#include<cstdio>
#include<iostream>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define LIST_LEN 100

namespace ArrayList {
	template <typename LData>
	class List {
		LData arr[LIST_LEN];
		int numofData;
		int curPosition;
	public:
		List() :numofData(0), curPosition(-1) {}
		void LInsert(LData data) {
			if (numofData == LIST_LEN) {
				puts("Max num of data Exceeded");
				return;
			}
			arr[numofData++] = data;
		}
		int LFirst(LData &data) {
			if (numofData != 0) {
				pdata = arr[0];
				curPosition = 0;
				return TRUE;
			}
			else
				return FALSE;
		}
		int LNext(LData &data) {
			if (curPosition < numofData - 1) {
				pdata = arr[++curPosition];
				return TRUE;
			}
			else
				return FALSE;
		}
		LData LRemove() {
			int i = 0;
			LData target = arr[curPosition--];
			if (numofData-- == 0) {
				puts("No data removable");
				return arr[curPosition];
			}
			for (i = curPosition + 1; i < numofData + 1; i++)
				arr[i] = arr[i + 1];
			return target;
		}
		int GetNData() { return numofData; }
		int GetCurPos() { return curPosition; }
	};
}
int main(void) {
	ArrayList::List<int> list;
	int data;

	list.LInsert(11);
	list.LInsert(11);
	list.LInsert(22);
	list.LInsert(22);
	list.LInsert(33);

	std::cout << "Now data is : " << list.GetNData() << std::endl;

	if (list.LFirst(data)) {
		printf("%d ", data);
		while (list.LNext(data))
			printf("%d ", data);
	}
	printf("\n\n");

	if (list.LFirst(data)) {
		if (data == 22)
			list.LRemove();
		while (list.LNext(data))
			if (data == 22)
				list.LRemove();
	}
	std::cout << "Now data is : " << list.GetNData() << std::endl;
	if (list.LFirst(data)) {
		printf("%d ", data);
		while (list.LNext(data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}