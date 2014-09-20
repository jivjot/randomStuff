#include "trie.h"
#include <iostream>
int main()
{
    std::string s("banana");
    trie t;
    for(int i = 0;i<s.size();i++)
    {
        t.insert(s.substr(i));
    }
    std::cout<<t.search("nananan")<<std::endl;
}
