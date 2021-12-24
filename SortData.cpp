#include "SortData.h"

#include <iostream>
#include <vector>
#include <chrono>

SortData::SortData(int n, int sizeData) {

    this->moveCount = 0;

    this->compCount = 0;

    this->totalTime = 0;

    this->sortName = " ";

    for(int i = 0; i < n ;i++) {

        this->keyVector.push_back(rand() % sizeData);

    }
}

SortData::~SortData() {

}

string SortData::getSortName() {

    return this->sortName;

}

int SortData::getMoveCount() {

    return this->moveCount;

}

int SortData::getCompCount() {

    return this->compCount;

}

chrono::time_point<chrono::high_resolution_clock> SortData::getBeginTime() {

    return this->beginTime;

}
chrono::time_point<chrono::high_resolution_clock> SortData::getEndTime() {

    return this->endTime;

}

float SortData::getTotalTime() {

    return this->totalTime;

}

void SortData::setMoveCount(int moveNumber) {

    this->moveCount = moveNumber;

}

void SortData::setCompCount(int compNumber) {

    this->compCount = compNumber;

}

void SortData::setSortName(string name) {

    this->sortName = name;

}

void SortData::setBeginTime(chrono::time_point<chrono::high_resolution_clock> start) {

    this->beginTime = start;

}

void SortData::setEndTime(chrono::time_point<chrono::high_resolution_clock> endd) {

 this->endTime = endd;

}

void SortData::setTotalTime(double total) {

    this->totalTime = total;

}

void SortData::addMoveCount() {
    this->moveCount++;
}
void SortData::addCompCount() {
    this->compCount++;
}

void SortData::setBeginTimeAction() {
    this->beginTime = chrono::high_resolution_clock::now();
}

void SortData::setEndTimeCut() {
    this->endTime = chrono::high_resolution_clock::now();
}

void SortData::defineTotalTime() {
    this->totalTime = chrono::duration_cast<chrono::milliseconds>(this->endTime - this->beginTime).count();
}

int SortData::getKeyVectorSize(){
    return this->keyVector.size();
}

int SortData::getIndexFromKeyVector(int index){
    return this->keyVector[index];
}
