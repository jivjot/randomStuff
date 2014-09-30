#include "trie.h"
#include <iostream>
#include <fstream>
int main()
{
    std::string s("banana");
    Trie t;
#if 0
    for(int i = 0;i<s.size();i++)
    {
        t.insert(s.substr(i));
    }
    std::cout<<t.search("banana")<<std::endl;
#endif
    {
        std::ifstream fin("input.in");
        while(fin.good())
        {
            std::string s;
            fin>>s;
            t.insert(s);
        }
        fin.close();
        t.depthFirstSearch("");
    }
    std::cout<<"Starting delete"<<std::endl;
    {
        std::ifstream fin("input.in");
        while(fin.good())
        {
            std::string s;
            fin>>s;
            t.deletePattern(s.c_str());
        }
        fin.close();
        t.depthFirstSearch("");
    }

}
