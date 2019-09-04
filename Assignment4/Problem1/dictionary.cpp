/**
  *
  * @author Ritik Jain
  * @date 25/08/2019
  * @file dictionary.cpp
  * @brief Dictionary File
  *
  */

#include "dictionary.h"
#include <string.h>
#include <fstream>

using namespace std;

Trie::Trie()
{
    root = nullptr;
}

Dictionary::Dictionary()
{
}

Trie::~Trie()
{
    delete root;
}

Dictionary::~Dictionary()
{

}

bool Trie::insert(char *word, char *mean)
{
    if(!word || !mean)
        return 0;

    word = strlwr(word);

    for(unsigned int i = 0; i < strlen(word); i++)
        if(word[i]<'a' || word[i]>'z')
            return 0;

    unsigned int i = 0;
    Node *tmp = nullptr;
    int j;
    unsigned int len = strlen(word);

    if(root)
    {
        tmp = root;
        while(i<len && tmp->c[j = word[i] - 'a'])
        {
            tmp = tmp->c[j];
            i++;
        }
    }
    else {

        root = new Node;
        root->v = nullptr;
        for(int p=0; p < ALPH_SIZ; p++)
            root->c[p] = nullptr;
        tmp = root;
    }

    if(i<len)
    {
    for(; i < len; i++)
    {
        j = word[i] - 'a';
        tmp->c[j] = new Node;
        for(int p=0; p < ALPH_SIZ; p++)
            if(tmp->c[j]->c[p])
            tmp->c[j]->c[p] = nullptr;
        tmp->v = nullptr;
        tmp = tmp->c[j];
    }
    }

    tmp->v = mean;

    return 1;
}

char* Trie::search(char *word)
{
    if(!word || !root)
        return nullptr;

    word = strlwr(word);

    for(unsigned int i = 0; i < strlen(word); i++)
        if(word[i]<'a' || word[i]>'z')
            return nullptr;

    Node *tmp = root;

    unsigned int i = 0;
    unsigned int len = strlen(word);
    int j;

    while(i<len && tmp->c[j = word[i] - 'a'])
    {
        tmp = tmp->c[j];
        i++;
    }

    if(i==len)
        return tmp->v;

    return nullptr;
}

char* Dictionary::format(char *s, int mod)
{
    if(!s)
        return nullptr;

    int len = strlen(s);

    if(mod)
    {
        char *fs = new char[len];
        fs = strcpy(fs,s);
        return fs;
    }

    int n=0;
    int j;
    bool ignore = false;

    for(j=0; j < len; j++)
    {
        if((s[j]>='A'&&s[j]<='Z')||(s[j]>='a'&&s[j]<='z'))
            n++;
        else {
            if(!ignore && s[j] == '"')
                ignore = 1;
            else if(ignore && s[j] == '"')
                ignore = 0;
            else if(ignore)
                n++;
        }
    }

    ignore = false;
    char *fs = new char[n+1];
    int i=0;
    for(j=0; j < len; j++)
    {
        if((s[j]>='A'&&s[j]<='Z')||(s[j]>='a'&&s[j]<='z'))
            fs[i++] = s[j];
        else {
            if(!ignore && s[j] == '"')
                ignore = 1;
            else if(ignore && s[j] == '"')
                ignore = 0;
            else if(ignore)
                fs[i++] = s[j];
        }
    }

    fs[n] = '\0';

    return fs;
}

char* Dictionary::trim(char *s)
{
    int j;

    for(j=0; j < strlen(s); j++ , s++)
        if(s[j]!=16 || s[j]!=20)
            break;

    for(j = strlen(s)-1; j >=0; j--)
        if(s[j]!=20 || s[j]!=16)
        {
            s[j+1] = '\0';
            break;
        }

    return s;
}

bool Dictionary::load(char *file)
{
    ifstream fin;
    fin.open(file);

    if(!fin)
        return 0;

    char buf[BUF_SZ];

    char *word, *mean;

    while(fin)
    {
        fin.getline(buf, BUF_SZ, ',');
        word = format(buf,0);
        fin.getline(buf, BUF_SZ, '\n');
        mean = trim(buf);
        if(mean[0]!='"')
        mean = format(mean,1);
        else
        mean = format(mean,0);

        data.insert(word, mean);
    }

    fin.close();

    return 1;
}

char* Dictionary::search(char* word)
{
    return data.search(word);
}
