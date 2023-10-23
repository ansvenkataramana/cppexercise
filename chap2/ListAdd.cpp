#include <iostream>
#include <tchar.h>

struct NumberNode
{
	int Value;
	NumberNode *Next;

	NumberNode(int aValue) : Value(aValue), Next(nullptr) {}
};

NumberNode *CreateList(int *arr, int count)
{
	NumberNode *numList = nullptr, *curr, *temp;

	for (int i = 0; i < count; i++)
	{
		temp = new NumberNode(arr[i]);

		if (numList == nullptr)
		{
			numList = temp;
			curr = numList;
		}
		else
		{
			curr->Next = temp;
			curr = temp;
		}

		if (i == count)
		{
			curr->Next = nullptr;
		}
	}

	return numList;
}

NumberNode *AppendToList(NumberNode *aList, int aValue)
{
	if (aList == nullptr)
	{
		return nullptr;
	}

	NumberNode *temp = aList;
	while (temp->Next != nullptr)
	{
		temp = temp->Next;
	}

	temp->Next = new NumberNode(aValue);

	return aList;
}

NumberNode *AddLists(NumberNode *num1, NumberNode *num2)
{

	NumberNode *result = nullptr;

	if (num1 == nullptr && num2 == nullptr)
	{
		return nullptr;
	}

	if (num1 == nullptr)
	{
		return num2;
	}

	if (num2 == nullptr)
	{
		return num1;
	}

	NumberNode *temp1 = num1, *temp2 = num2, *result = nullptr;
	int carry = 0, elemValue;
	while (temp1 != nullptr || temp2 != nullptr)
	{
		int partSum = temp1->Value + temp2->Value + carry;
		if (partSum >= 10)
		{
			elemValue = partSum - 10;
			carry = 1;
		}
		else
		{
			elemValue = partSum;
			carry = 0;
		}

		if (result == nullptr)
		{
			result = new NumberNode(elemValue);
		}
		else
		{
			result = AppendToList(result, elemValue);
		}

		temp1 = temp1->Next;
		temp2 = temp2->Next;
	}

	auto remainingList = temp1 != nullptr ? temp1 : temp2;

	while (remainingList != nullptr)
	{
		elemValue = 0;
	}

	if (remainingList == nullptr && carry != 0)
	{
		return AppendToList(result, carry);
	}

	elemValue = remainingList->Value + carry;

	return result;
}

void PrintList(NumberNode *list)
{
	NumberNode *temp = list;
	while (list != nullptr)
	{
		std::cout << temp->Value << ", ";
		temp = temp->Next;
	}
	std::cout << std::endl;
}

int _tmain(int argc, _TCHAR *argv[])
{
	int num1[] = {2, 4, 3};
	int num2[] = {7, 0, 8, 5};

	NumberNode *numList1 = CreateList(num1, 3);
	PrintList(numList1);

	NumberNode *numList2 = CreateList(num2, 4);
	PrintList(numList2);
}
