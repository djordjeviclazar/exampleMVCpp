#include <string.h>
#include <stdio.h>

void Downheap(int* arrayEl, int index, int length)
{
	int pom, childIndex = index << 1, newIndex;
	bool change = false;
	if (childIndex >= length) { return; }

	pom = arrayEl[childIndex++];
	if (childIndex <= length && pom < arrayEl[childIndex])
	{
		pom = arrayEl[childIndex];
	}
	else
	{
		childIndex--;
	}

	if (pom > arrayEl[index])
	{
		change = true;

		arrayEl[childIndex] = arrayEl[index];
		arrayEl[index] = pom;

		newIndex = childIndex;
	}

	if (change)
	{
		Downheap(arrayEl, newIndex, length);
	}
}

void Upheap(int* arrayEl, int index, int length)
{
	int parentIndex = ((index + 1) >> 1) - 1, newIndex;
	bool change = false;

	if (arrayEl[index] > arrayEl[parentIndex])
	{
		change = true;

		int pom = arrayEl[parentIndex];
		arrayEl[parentIndex] = arrayEl[index];
		arrayEl[index] = pom;

		newIndex = parentIndex;
	}

	if (newIndex > 0 && change)
	{
		Upheap(arrayEl, newIndex, length);
	}
}

void Heapify(int* arrayEl, int length)// max-heap
{
	for (int i = (length >> 1); i >= 0; i--)
	{
		Downheap(arrayEl, i, length);
	}
}

bool AreStringsIsomorphic(char* a, char* b)
{
	// initialization:
	const int alphabetLength = 'z' - 'a';
	int counterA[alphabetLength], counterB[alphabetLength];
	for (int i = 0; i < alphabetLength; i++)
	{
		counterA[i] = 0;
		counterB[i] = 0;
	}

	// search:
	const int lengthA = strlen(a), lengthB = strlen(b);
	if (lengthA != lengthB) { return false; }

	for (int i = 0; i < lengthA; i++)
	{
		counterA[a[i] - 'a']++;
		counterB[b[i] - 'a']++;
	}

	Heapify(counterA, alphabetLength);
	Heapify(counterB, alphabetLength);
	
	// compare:
	bool result = true;
	int pom;
	for (int i = alphabetLength - 1; i >= 0; i--)
	{
		// compare root:
		if (counterA[0] != counterB[0])
		{
			result = false;
			break;
		}

		if (counterA[0] == 0) { break; }

		// delete:
		pom = counterA[i];
		counterA[i] = counterA[0];
		counterA[0] = pom;
		Downheap(counterA, 0, i);

		pom = counterB[i];
		counterB[i] = counterB[0];
		counterB[0] = pom;
		Downheap(counterB, 0, i);
	}

	if (result)
	{
		printf("true \r\n");
	}
	else
	{
		printf("false \r\n");
	}
	return result;
}

int main()
{
	// test:
	char* a = new char[6], * b = new char[6];

	strcpy(a, "brain");
	strcpy(b, "space");
	AreStringsIsomorphic(a, b);
	// exp: true

	strcpy(a, "noon");
	strcpy(b, "feet");
	AreStringsIsomorphic(a, b);
	// exp: false

	strcpy(a, "aab");
	strcpy(b, "ccd");
	AreStringsIsomorphic(a, b);
	// exp: true

	strcpy(a, "loot");
	strcpy(b, "feet");
	AreStringsIsomorphic(a, b);

	delete[] a;
	delete[] b;

	getchar();
	return 0;
}