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

    float TotalTime[5];

    Sorts HeapSort(n);

    vector<TikTokData> cringeData;

    ofstream input("saídas.txt", ios::app);

    input << "Heap Sort p/ N = " << n << endl;
    input << "Comparações, Movimentos, Tempo de execução" << endl;
    cringeData = fr.readTikTok("tiktok_app_reviews.csv");
    input.close();

    for(int i = 0; i < n; i++) {

        HeapSort.heapSortInsert(part2[i], &cringeData);

    }

}


int main()
{

    callHeapSort(10000);

    int n = 50000;

    n = 100000;

    n = 500000;

    n = 1000000;

    //Sorts c(n);
    std::vector<TikTokData> dados;
    return 0;
}
