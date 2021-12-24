#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

#include "FileReader.h"
#include "moduloteste.h"
#include "Sorts.h"
#include "SortData.h"
#include "TikTokData.h"

using namespace std;

void callHeapSort(int n) {

    FileReader fr;

    int comps[5];

    int moves[5];

    float TotalTimes[5];

    Sorts HeapSort(n);

    vector<TikTokData> cringeData;

    ofstream input("saída.txt", ios::app);

    input << "Heap Sort p/ N = " << n << endl;

    input << "Comparações, Movimentos, Tempo de execução" << endl;

    cringeData = fr.readTikTok("tiktok_app_reviews.csv");

    input.close();

    for(int i = 0; i < 5; i++) {

        srand(i);

        SortData *sortsInfo = new SortData(n, n);

        vector<TikTokData> ol(n);

        for (int j = 0; j < sortsInfo->getKeyVectorSize(); j++) {

            ol[j] = cringeData[sortsInfo->getIndexFromKeyVector(j)];

        }

        sortsInfo->setBeginTimeAction();

        for (int k = 0; k < n; k++) {

         HeapSort.heapSortInsert(ol[k], sortsInfo);

        }

        sortsInfo->setEndTimeCut();

        sortsInfo->defineTotalTime();

        fr.writeInFile(ol);

        moves[i] = sortsInfo->getMoveCount();

        comps[i] = sortsInfo->getCompCount();

        TotalTimes[i] = sortsInfo->getTotalTime();

        delete sortsInfo;

    }

    float moveMedia = (moves[0] + moves[1] + moves[2] + moves[3] + moves[4])/ 5;

    float compsMedia = (comps[0] + comps[1] + comps[2] + comps[3] + comps[4])/ 5;

    float totalMedia = (TotalTimes[0] + TotalTimes[1] + TotalTimes[2] + TotalTimes[3] + TotalTimes[4])/ 5;

    ofstream results("saída.txt",ios::app);

    results << "Médias: " << fixed << setprecision(3) << moveMedia << ", " << compsMedia << ", " << totalMedia << endl << endl;

    results.close();

}

void callQuickSort(int n) {

    FileReader fr;

    int comps[5];

    int moves[5];

    float TotalTimes[5];

    Sorts QuickSort(0);

    vector<TikTokData> cringeData;

    ofstream input("saída.txt", ios::app);

    input << "Quick Sort p/ N = " << n << endl;

    input << "Comparações, Movimentos, Tempo de execução" << endl;

    cringeData = fr.readTikTok("tiktok_app_reviews.csv");

    input.close();

    for(int i = 0; i < 5; i++) {

        srand(i);

        SortData *sortsInfo = new SortData(n, n);

        vector<TikTokData> ol(n);

        for (int j = 0; j < sortsInfo->getKeyVectorSize(); j++) {

            ol[j] = cringeData[sortsInfo->getIndexFromKeyVector(j)];

        }

        sortsInfo->setBeginTimeAction();

        QuickSort.quickSort(ol, 0, ol.size(), sortsInfo);

        sortsInfo->setEndTimeCut();

        sortsInfo->defineTotalTime();

        fr.writeInFile(ol);

        moves[i] = sortsInfo->getMoveCount();

        comps[i] = sortsInfo->getCompCount();

        TotalTimes[i] = sortsInfo->getTotalTime();

        delete sortsInfo;

    }

    float moveMedia = (moves[0] + moves[1] + moves[2] + moves[3] + moves[4])/ 5;

    float compsMedia = (comps[0] + comps[1] + comps[2] + comps[3] + comps[4])/ 5;

    float totalMedia = (TotalTimes[0] + TotalTimes[1] + TotalTimes[2] + TotalTimes[3] + TotalTimes[4])/ 5;

    ofstream results("saída.txt",ios::app);

    results << "Médias: " << fixed << setprecision(3) << moveMedia << ", " << compsMedia << ", " << totalMedia << endl << endl;

    results.close();

}

void callCountingSort(int n) {

    FileReader fr;

    int comps[5];

    int moves[5];

    float TotalTimes[5];

    Sorts CountingSort(0);

    vector<TikTokData> cringeData;

    ofstream input("saída.txt", ios::app);

    input << "Counting Sort p/ N = " << n << endl;

    input << "Comparações, Movimentos, Tempo de execução" << endl;

    cringeData = fr.readTikTok("tiktok_app_reviews.csv");

    input.close();

    for(int i = 0; i < 5; i++) {

        srand(i);

        SortData *sortsInfo = new SortData(n, n);

        vector<TikTokData> ol(n);

        for (int j = 0; j < sortsInfo->getKeyVectorSize(); j++) {

            ol[j] = cringeData[sortsInfo->getIndexFromKeyVector(j)];

        }

        sortsInfo->setBeginTimeAction();

        CountingSort.countingSort(ol, sortsInfo);
        //vector<TikTokData> &data, SortData *info

        sortsInfo->setEndTimeCut();

        sortsInfo->defineTotalTime();

        fr.writeInFile(ol);

        moves[i] = sortsInfo->getMoveCount();

        comps[i] = sortsInfo->getCompCount();

        TotalTimes[i] = sortsInfo->getTotalTime();

        delete sortsInfo;

    }

    float moveMedia = (moves[0] + moves[1] + moves[2] + moves[3] + moves[4])/ 5;

    float compsMedia = (comps[0] + comps[1] + comps[2] + comps[3] + comps[4])/ 5;

    float totalMedia = (TotalTimes[0] + TotalTimes[1] + TotalTimes[2] + TotalTimes[3] + TotalTimes[4])/ 5;

    ofstream results("saída.txt",ios::app);

    results << "Médias: " << fixed << setprecision(3) << moveMedia << ", " << compsMedia << ", " << totalMedia << endl << endl;

    results.close();

}

void callSorts() {

    callHeapSort(10000);

    callHeapSort(50000);

    callHeapSort(100000);

    callHeapSort(500000);

    callHeapSort(1000000);


    callQuickSort(10000);

    callQuickSort(50000);

    callQuickSort(100000);

    callQuickSort(500000);

    callQuickSort(1000000);


    callCountingSort(10000);

    callCountingSort(50000);

    callCountingSort(100000);

    callCountingSort(500000);

    callCountingSort(1000000);

}

int main()
{

    callSorts();

    return 0;
}
