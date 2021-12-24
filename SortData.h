#ifndef SORTDATA_H_INCLUDED
#define SORTDATA_H_INCLUDED

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class SortData
{
    private:

        string sortName;

        int moveCount;
        ///número de movimentações

        int compCount;
        ///número de comparações

        chrono::time_point<chrono::high_resolution_clock> beginTime;
        ///horário de início

        chrono::time_point<chrono::high_resolution_clock> endTime;
        ///horário de término

        float totalTime;
        ///tempo total

        vector<int> keyVector;
        ///vetor de índices aleatórios

    public:

        SortData(int n, int dataSize);
        ~SortData();

        string getSortName();

        int getMoveCount();
        int getCompCount();

        chrono::time_point<chrono::high_resolution_clock> getBeginTime();
        chrono::time_point<chrono::high_resolution_clock> getEndTime();
        float getTotalTime();

        void setSortName(string sortName);

        void setMoveCount(int moveNumber);
        void setCompCount(int compNumber);

        void setBeginTime(chrono::time_point<chrono::high_resolution_clock> startTime);
        void setEndTime(chrono::time_point<chrono::high_resolution_clock> endTime);
        void setTotalTime(double TotalTime);

        void addMoveCount();
        void addCompCount();

        void setBeginTimeAction();
        void setEndTimeCut();
        void defineTotalTime();

        int getKeyVectorSize();
        int getIndexFromKeyVector(int index);
};

#endif // SORTDATA_H_INCLUDED
