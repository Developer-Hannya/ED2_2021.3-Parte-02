#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <fstream>
#include <time.h>
#include <vector>
#include <string>
#include <iomanip>

#include "SortData.h"
#include "moduloteste.h"
#include "TikTokData.h"
#include "Sorts.h"
#include "FileReader.h"
#include "moduloteste.h"

using namespace std;

void setSortName(std::vector<SortData> sd) {

    for (int i = 0; i < 3; i++) {

        switch(i) {

            case 0:

                sd[0].setSortName("Heap Sort");

                break;

            case 1:

                sd[1].setSortName("Quick Sort");

                break;

            case 2:

                sd[0].setSortName("Counting Sort");

                break;

            default:

                break;

        }

    }

}

int main()
{
    std::vector<TikTokData> dados;
    vector<TikTokData> t;
    int i;
    cout << "[1] ordenacao" << endl << "[2] Hash" << endl << "[3] Modulo de teste"<< endl ;
    cin >> i;
    for(int j=0; j<100 ; j++)
    {
        srand(time(NULL));
        int a = rand()%3500000;
        t.at(j).setId(dados.at(a).getId());
        t.at(j).setReview(dados.at(a).getReview());
        t.at(j).setUpVotes(dados.at(a).getUpVotes());
        t.at(j).setAppVersion(dados.at(a).getAppVersion());
        t.at(j).setPostDate(dados.at(a).getPostDate());

    }
    if(i==1)
    {
        Sorts *ord= new Sorts();
        ord->quickSort(dados,dados.begin(),dados.end(),SortData * info);
        ord->heapSort();
        ord->countingSort(dados,dados.size());
        delete[] ord;
    }
    else if(i==2)
    {
        int m;
        cout<< "Digite a quantidade das versoes mais frequentes:" << endl;
        cin>>m;
        hash *version = new Hash;
        version->versions(dados,dados.size(),m);
        delete[] version;

    }
    else if(i==3)
    {
        Sorts *ordTeste= new Sorts();
        hash *version1 = new Hash;
        ofstream arquivotxt;
        arquivotxt.open("teste.txt",ios::binary);
        if (!arquivotxt.is_open())
        {
            cout << " ERRO: Arquivo nao aberto. " << endl;
            return  1 ;
        }
        arquivotxt<<ordTeste->quickSort(t,t.begin(),t.end(),SortData * info)<< endl;
        arquivotxt<<ordTeste->heapSort()<< endl;
        arquivotxt<<ordTeste->countingSort(dados,dados.size());
                << endl;
        arquivotxt<<version1->versions(dados,dados.size(),m);

        arquivotxt.close();
        delete[] ordTeste;
        delete[] version1;
    }
    else
        cout<<"operacao invalida"<<endl;

    return 0;
}
