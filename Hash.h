#ifndef Hash_H_INCLUDED
#define Hash_H_INCLUDED

#include <vector>
#include <bits/stdc++.h>
#include "string.h"

class Hash
{
    private:
        int bucket;
        vector<int> frequencia,serial;

        list<string> *tabela;

        int chave(string ver);

    public:
        Hash(int N);

        void versions(vector <tiktokdata>,int N,int M);
        void insereItem(string chave);
        void deletaItem(string chave);
        int funcaohash(string x);
        int chave(string ver);
};

#endif
