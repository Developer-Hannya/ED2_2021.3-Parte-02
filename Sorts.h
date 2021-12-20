#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED

#include <iostream>
#include <vector>
#include <chrono>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <array>

#include "TikTokData.h"
#include "SortData.h"
#include "moduloteste.h"

class Sorts {

    private:

        int heapSortMaxReviews;
        /// capacidade m�xima de reviews no Heap Sort

        int heapSortNReviews;
        /// total de reviews encadeados no Heap Sort

        TikTokData *heapSortArray;
        /// vetor que armazena a heap do Heap Sort

        void heapSortRise(TikTokData d, SortData *info);
        ///fun��o de subir o review do Heap Sort

        void heapSortDrop(TikTokData d, SortData *info);
        ///fun��o de descer o review do Heap Sort

        void quickSortPartition(vector<TikTokData> dados, int lowIndex, int highIndex);
        ///fun��o de parti��o do Quick Sort

    public:

        Sorts(int heapSortNReviews);
        ~Sorts();

        void quickSort(vector<TikTokData> &data, int lowIndex, int highIndex, SortData *info);
        int partitionQuickSort(vector<TikTokData> &dados, int lowIndex, int highIndex, SortData *info);

        TikTokData heapSortGetRoot();
        heapSortGetPositionFromElement(TikTokData d);
        void heapSortInsert(TikTokData d, SortData *info);

        void countingSort(vector<TikTokData> dados, int n);

};


#endif // SORTS_H_INCLUDED
