#include <iostream>
#include <fstream>
#include <time.h>

#include "moduloteste.h"

using namespace std;

moduloteste::moduloteste()
{
};

moduloteste::~moduloteste()
{
};

void moduloteste::acessaRegistro(int i, vector<TikTokData> dados) {

    cout << "Id: " << dados.at(i).getId() << endl;

    cout << "Review: " << dados.at(i).getReview() << endl;

    cout << "UpVotes: " << dados.at(i).getUpVotes() << endl;

    cout << "AppVersion: " << dados.at(i).getAppVersion() << endl;

    cout << "PostDate: " << dados.at(i).getPostDate() << endl;

};

void moduloteste::testeImportacao(vector<TikTokData> dados) {
    int i, couti;

    std::cout << "[1] exibir saida" << std::endl << "[2] salvar em arquivo texto" << std::endl;

    std::cin >> i;

    if(i == 1) {

        int ale;

        for(couti = 0; couti < 10; couti++) {

           srand (time(NULL));

           ale = rand() % 3500000;

           std::cout << "Registro " << couti + 1 << ": " << std::endl;

           std::cout << "Id: " << dados.at(i).getId() << std::endl;

           std::cout << "Review: " << dados.at(i).getReview() << std::endl;

           std::cout << "UpVotes: " << dados.at(i).getUpVotes() << std::endl;

           std::cout << "AppVersion: " << dados.at(i).getAppVersion() << std::endl;

           std::cout << "PostDate: " << dados.at(i).getPostDate() << std::endl;

        }

    }
    else if(i == 2) {

        int ale;

        ofstream wr;

        wr.open("data.bin",ios::binary);

        if(!wr.is_open()) {

            cout << "ERRO:Arquivo nao aberto." << endl;

            exit(1);

        }

        for(couti = 0; couti < 100; couti++) {

            srand (time(NULL));

            ale = rand() % 3500000;

            vector<TikTokData> text;

            text.at(couti).setId(dados.at(ale).getId());

            text.at(couti).setReview(dados.at(ale).getReview());

            text.at(couti).setUpVotes(dados.at(ale).getUpVotes());

            text.at(couti).setAppVersion(dados.at(ale).getAppVersion());

            text.at(couti).setPostDate(dados.at(ale).getPostDate());


            wr.write((char *) &text.at(couti), sizeof(text.at(couti)));

        }

        wr.close();

    }

    else {

        cout << "ERRO:Operacao invalida."<< endl;

        exit(1);

    }

};

void moduloteste::randomImport(vector<TikTokData> data, vector <TikTokData> vectorRandom, int n) {

    for(int i = 0; i < n; i++) {
        vectorRandom[i] = data[rand() % 35000000];
    }

}
