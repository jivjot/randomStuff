#ifndef trie_h
#define trie_h
#include <string>

class trie
{
    static const int size = 256;
    char c;
    trie * child[size];
    public:
    trie()
    {
        c = -1;//not leaf 0 end of string
        for(int i = 0;i<size;i++)
        {
            child[i] = NULL;
        }
    }
    ~trie()
    {
        for(int i = 0;i<size;i++)
        {
            if(child[i] != NULL)
            {
                delete child[i];
                child[i] = NULL;
            }
        }
    }
    void insert(const char*str)
    {
        if(*str == '\0')
        {
            c = 0;
            return;
        }
        if(child[*str] == NULL)
        {
            child[*str] = new trie;
        }
        child[*str]->insert(str+1);
    }
    void insert(const std::string &s)
    {
        insert(s.c_str());
    }
    bool search(const char*str) const
    {
        if(str == '\0')
        {
            return true;
        }
        if(child[*str] != NULL)
        {
            if(*(str + 1) == '\0' && c == 0)
                return true;
            return child[*str]->search(str + 1);
        }
        return false;
    }
    bool search(const std::string &s) const
    {
        return search(s.c_str());
    }

};
#endif
