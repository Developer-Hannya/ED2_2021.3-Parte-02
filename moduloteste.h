#ifndef moduloteste_H_INCLUDED
#define moduloteste_H_INCLUDED

#include <vector>

class moduloteste
{
    public:
       moduloteste();
       ~moduloteste();

       void acessaRegistro(int i,vector<TikTokData> dados);
       void testeImportacao(vector<TikTokData> dados);

};

#endif
