#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include <bits/stdc++.h>
#include <stdio.h>

#include "hash.h"


using namespace std;

Hash::Hash(int N)
{
    this->bucket = N;
    tabela = new list<string>[bucket];
}

void Hash::versions(vector <tiktokdata>,int n,int m)
{
    int random,maior=0;
    ifstream rd;
    rd.open("tiktokdata.bin",ios::binary);
    if(!rd.is_open())
    {
        cout<< "ERRO:Arquivo nao aberto."<< endl;
        return;
    }

    for(int count = 0;count < n;count++)
    {
        bool armazenado = false;
        //verifica se a hash ja esta armazenando a versao.
        for(vector<int> iterator i = serial.begin();i != serial.end();i++)
        {
            if(chave(tiktokdata.at(random).getAppVersion) == serial.at(i))
            {
                armazenado = true;
                frequencia.at(i) = frequencia.at(i) + 1;
            }
        }
        //insere a versao na hash e armazena nos vectors serial e frequencia.
        if(armazenado == false)
        {
            srand(time(NULL));
            random = rand() % 3500000;
            insereItem(tiktokdata.at(random).getAppVersion);
            serial.push_back(chave(tiktokdata.at(random).getAppVersion));
            frequencia.push_back(1);
        }
    }
    //determina o maior elemento.
    for(int i = 0;i != frequencia.end();i++)
    {
        if(frequencia.at(i) > maior)
        {
            maior = frequencia.at(i);
        }
    }
    //faz busca dos M versoes com maiores frequencia.
        while(m > 0)
        {
            bool achado = false;

            for(int b = 0;b != frequencia.end();b++)
            {
                if(frequencia.at(b) == maior)
                {
                    //busca pela versao que possui o mesmo numero serial da posicao em que se encontra a maior frequencia.
                    for(int i = 0; i < bucket; i++)
                    {
                        for(auto x : tabela[i])
                        {
                            if(chave(x) == serial.at(b))
                            {
                                //se encontrado, ira imprimi-lo e reduzira o maior procurado e diminuira os elementos restantes para a impressao.
                                cout << puts(x) << " : " << frequencia.at(b) << endl;
                                achado = true;
                                maior--;
                                m--;
                            }
                        }
                    }
                }
            }

            if(achado == false)
              maior--;
        }

    rd.close();
}

void Hash::insereItem(string chave)
{
    int index = funcaohash(chave);
    tabela[index].push_back(chave);
}

void Hash::deletaItem(string chave)
{
    int index = funcaohash(chave);

    list <string> :: iterator i;
    for(i = tabela[index].begin();i != tabela[index].end();i++)
    {
        if(*i == key)
            break;
    }

    if(i != tabela[index].end())
        tabela[index].erase(i);
}

int Hash::funcaohash(string s)
{
    int key = chave(s);
    return (key % bucket);
}

int Hash::chave(string ver)
{
    int chav = 0,factor = 0;
    for(int i = ver.length();i >= 0;i--)
    {
        if(ver[i] >= 48 && ver[i] <=57)
        {
            chav=chav + (((int)ver[i] - 48) * pow(10,factor));
            factor++;
        }
        else
           factor = 0;
    }
    return chav;
}

void Hash::displayHash()
{
    for(int i = 0; i < bucket; i++)
    {
        cout << i;
        for(auto x : tabela[i])
          cout << "--> " << x;
        cout << endl;  
    }
}
