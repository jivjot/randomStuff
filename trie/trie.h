#ifndef trie_h
#define trie_h
#include <string>

class Trie
{
    static const int size = 256;
    long long _counter;
    long long _childCounter;
    Trie * _child[size];
    public:
    Trie()
    {
        _counter = 0;
        _childCounter = 0;
        for(int i = 0;i<size;i++)
        {
            _child[i] = NULL;
        }
    }
    ~Trie()
    {
        for(int i = 0;i<size;i++)
        {
            if(_child[i] != NULL)
            {
                delete _child[i];
                _child[i] = NULL;
            }
        }
    }
    void insert(const char*str)
    {
        if(*str == '\0')
        {
            _counter++;
            return;
        }

        if(_child[*str] == NULL)
        {
            _child[*str] = new Trie();
            _childCounter++;
        }
        _child[*str]->insert(str+1);

    }
    void insert(const std::string &s)
    {
        insert(s.c_str());
    }
    bool deletePattern(const char *str)
    {
        if(*str == '\0')
        {
            _counter--;
        }
        else if(_child[*str] != NULL)
        {
            if(_child[*str]->deletePattern(str + 1))
            {
                _childCounter--;
                delete _child[*str];
                _child[*str] = NULL;
            }
        }
        
        if(_counter <= 0 && _childCounter <= 0)
            return true;
        else
            return false;
    }
    bool search(const char*str) const
    {
        if(*str == '\0')
            return true;
        else if(_child[*str] != NULL)
        {
            return _child[*str]->search(str + 1);
        }
        else
            return false;
    }
    bool search(const std::string &s) const
    {
        return search(s.c_str());
    }

};
#endif
