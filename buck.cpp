/*
 * =====================================================================================
 *
 *       Filename:  buck.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/11/2017 07:20:13 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Muhammad Usman (), uthmanhere@gmail.com
 *   Organization:  SEECS, NUST
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <list>


using namespace std;

#define SIZE 10


void buck_sort(float *, size_t);

int main()
{
	float * data = new float[SIZE];
	
	list <float> this_list;

	for (int counter = 0; counter < SIZE; ++counter)
	{
		data[counter] = 1 / (float)(SIZE - counter + 2);
		printf(" %f", data[counter]);
	}
	puts("");

	buck_sort(data, SIZE);
	
	for (int counter = 0; counter < SIZE; ++counter)
	{
		printf(" %f", data[counter]);
	}

	puts("");
	
	delete[] data;
	
	return 0;
}

void buck_sort(float * data, size_t size)
{
	list <float> sorting_arrayList[SIZE];
	puts("Gonna deal sorting array");
	for (int counter = 0; counter < size; ++counter)
	{
		sorting_arrayList[(int)(size * data[counter])].push_back(data[counter]);
	}

	puts("Done with sortingArray");
	for (int counter = 0; counter < 10; ++counter) {
	for (auto it = sorting_arrayList[counter].begin(); it != sorting_arrayList[counter].end(); ++it)
		printf(" %f", *it);
	puts("");
	}


	for (unsigned int counter = 0; counter < size; ++counter)
	{
			auto it1 = sorting_arrayList[counter].begin();
			auto it2 = it1;
			++it2; 
			do {
		//	puts("Phans gya");
			if (*it1 < *it2)
			{
				while (*it1 > *it2 && it1 != sorting_arrayList[counter].begin())
				{
					--it1;
				}
				++it1;
				printf("it1: %f, it2:%f\n", *it1, *it2);
				swap(*it1, *it2);
				printf("it1: %f, it2:%f\n", *it1, *it2);

	for (int count = 0; count < 10; ++count) {
	for (auto it = sorting_arrayList[count].begin(); it != sorting_arrayList[count].end(); ++it)
		printf(" %f", *it);
	puts("");
	
			}
			}
			++it2;
			it1 = it2;
			--it1;
			} while (it2 != sorting_arrayList[counter].end());
	}
	for (int counter = 0; counter < 10; ++counter) {
	for (auto it = sorting_arrayList[counter].begin(); it != sorting_arrayList[counter].end(); ++it)
		printf(" %f", *it);
	puts("");
	}

	for (int counter = 0; counter < size - 1; ++counter)
		sorting_arrayList[0].merge(sorting_arrayList[counter + 1]);

	for (int counter = 0; counter < size; ++counter)
	{
		data[counter] = sorting_arrayList[0].front();
		sorting_arrayList[0].pop_front();
	}
}

