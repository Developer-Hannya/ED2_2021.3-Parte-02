#include "Sorts.h"

Sorts::Sorts(int maxReviews){

    this->heapSortMaxReviews = maxReviews;

    this->heapSortNReviews = 0;

    this->heapSortArray = new TikTokData[this->heapSortMaxReviews];

}

Sorts::~Sorts(){

    delete this;

}

/*
TikTokData Sorts::heapSortGetRoot() {

    if (this->heapSortNReviews > 0) {

        return this->heapSortArray[0];

    }
    else {

        cout << "no momento a Heap se encontra vazia" << endl;

        exit(1);

    }
}
*/

void Sorts::heapSortInsert(TikTokData d, SortData *info) {

    if(this->heapSortNReviews < this->heapSortMaxReviews) {

        heapSortArray[heapSortNReviews] = d;

        heapSortNReviews += 1;

        heapSortRise(heapSortArray[heapSortNReviews - 1], info);

    }
}

int Sorts::heapSortGetPositionFromElement(TikTokData d) {

    for (int i = 0; i < sizeof(heapSortArray); i++) {

        if(&heapSortArray[i].getUpVotes == &d.getUpVotes) {

            return i;

        }
    }
}

void Sorts::heapSortRise(TikTokData d, SortData *info) {

    int fatherIndex = (heapSortGetPositionFromElement(d) - 1)/ 2;

    if(heapSortArray[fatherIndex].getUpVotes() < d.getUpVotes()) {

        info->addCompCount();

        swap(heapSortArray[fatherIndex], d);

        info->addMoveCount();

        heapSortRise(heapSortArray[fatherIndex], info);
    }
    else {

        info->addCompCount();

    }
}

/*
void Sorts::heapSortDrop(TikTokData father, SortData *info) {

    int maxChildIndex = 2 * heapSortGetPositionFromElement(father) + 1;

    if(maxChildIndex < heapSortNReviews) {

        info->addCompCount();

        if(maxChildIndex + 1 < heapSortNReviews) {

            info->addCompCount();

            if(heapSortArray[maxChildIndex + 1].getUpVotes() > heapSortArray[maxChildIndex].getUpVotes()) {

                info->addCompCount();

                maxChildIndex++;

            }

            else {

                info->addCompCount();

            }

        }

        else {

            info->addCompCount();

        }

        if(father.getUpVotes() < heapSortArray[maxChildIndex].getUpVotes()) {

            info->addCompCount();

            swap(father, heapSortArray[maxChildIndex]);

            info->addMoveCount();

            heapSortDrop(heapSortArray[maxChildIndex], info);

        }

        else {

            info->addCompCount();

        }

    }

    else {

        info->addCompCount();

    }

}
*/


int Sorts::partitionQuickSort(vector<TikTokData> &data, int lowIndex, int highIndex, SortData *info) {

    int i = lowIndex;

    int j = highIndex;

    TikTokData pivot = data[(lowIndex + highIndex)/2];

      do {

        info->addCompCount();

        while(data[i].getUpVotes() < pivot.getUpVotes()) {

            i++;

            info->addCompCount();

        }

        info->addCompCount();

        while(data[j].getUpVotes() > pivot.getUpVotes()) {
            j--;

            info->addCompCount();

        }

        if(i <= j) {

            swap(data[i],data[j]);

            info->addMoveCount();

            i++;

            j--;
        }

    }while (i <= j);

    return i;

}

void Sorts::quickSort(vector<TikTokData> &data, int lowIndex, int highIndex, SortData *info) {

    if(highIndex - lowIndex > 0) {

        int middl = partitionQuickSort(data, lowIndex, highIndex, info);

        quickSort(data, lowIndex, middl - 1, info);

        quickSort(data, middl, highIndex, info);
    }
}


void Sorts::countingSort(vector<TikTokData> &data, SortData *info) {

    int maxVotes = data[0].getUpVotes(), minVotes = data[0].getUpVotes();

    for(int i = 1; i < data.size();i++) {

        if(data[i].getUpVotes() > maxVotes) {

            maxVotes = data[i].getUpVotes();

        }

        if(data[i].getUpVotes() < minVotes) {

            minVotes = data[i].getUpVotes();

        }

    }

    int range = maxVotes - minVotes + 1;

    vector<int> count(range);

    for(int i = 0; i < data.size(); i++) {

        count[data[i].getUpVotes() - minVotes]++;

    }

    for(int i = 1; i < count.size(); i++) {

        count[i] += count[i - 1];
    }

    vector<TikTokData> sorter(data.size());

    for(int i = data.size() - 1; i >= 0; i--) {

        sorter[count[data[i].getUpVotes() - minVotes] - 1] = data[i];

        if(count[data[i].getUpVotes() - minVotes] - 1 != i) {

            info->addMoveCount();
        }

        count[data[i].getUpVotes() - minVotes]--;
    }

    for(int i = 0; i < data.size();i++) {

        data[i] = sorter[i];

    }
}
