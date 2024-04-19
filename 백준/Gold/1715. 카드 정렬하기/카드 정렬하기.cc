#include <stdio.h>

// 부모 노드 index >> 1
// 자식 노드 왼 index << 1 , 오 index << 1 + 1

int MinHeap[100001];
int size = 0;

inline void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Push(int num)
{
	MinHeap[++size] = num;

	if (size != 1)
	{
		int curIndex = size;
		int parent = size >> 1;

		while (parent)
		{
			if (MinHeap[curIndex] < MinHeap[parent])
				Swap(MinHeap[curIndex], MinHeap[parent]);
			else
				break;

			curIndex = parent;
			parent = curIndex >> 1;
		}
	}
}

int Pop()
{
	if (size == 0)
		return -1;

	int ret = MinHeap[1];
	MinHeap[1] = MinHeap[size--];

	int curIndex = 1;
	int child = 2;

	while (child <= size)
	{
		if (child + 1 <= size)
		{
			child = MinHeap[child] < MinHeap[child + 1] ? child : child + 1;
		}

		if (MinHeap[child] < MinHeap[curIndex])
		{
			Swap(MinHeap[curIndex], MinHeap[child]);
		}
		else
			break;

		curIndex = child;
		child = curIndex << 1;
	}

	return ret;
}

int main()
{

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		Push(num);
	}

	int a = Pop();
	int b = Pop();

	int sum = a + b;

	Push(sum);

	while (size > 1)
	{
		a = Pop();
		b = Pop();

		int sum2 = a + b;
		Push(sum2);

		sum += sum2;
	}

	printf("%d", sum);

	return 0;
}