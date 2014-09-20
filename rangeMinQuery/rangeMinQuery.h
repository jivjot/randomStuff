#ifndef rangeMinQuery_h
#define rangeMinQuery_h
template <class T,typename CMP>
class RangeMinimumQuery
{
    std::vector<T> _range
    std::vector<std::vector<int> > _tree;
    CMP _cmp;
    void updateLevelone(const int &index,
            const int &index1,
            const int &index2)
    {
        if(index2 >= _range.size())
        {
            _tree[level - 1][index] = index1;
        }
        else if(_cmp(_range[index1],_range[index2]))
        {
            _tree[level - 1][index] = index1;
        }
        else
        {
            _tree[level-1][index] = index2;
        }

    }

    void updateLevel(const int &level,
            const int &index,
            const int & index1,
            const int &index2)
    {
        if(index2 >= _tree[level - 2].size())
        {
            _tree[level - 1][index] = index1;
        }
        else if(_cmp(_range[_tree[level - 2][index1]],
                    _tree[level - 2][index2]))
        {
            _tree[level - 1][index] = index1;
        }
        else
        {
            _tree[level-1][index] = index2;
        }

    }
    void update(const int &level,const int &index)
    {
        if(level == 0)
        {
            update(level+1,index/2);
        }
        else 
        {
            if(level -1 >= _tree.size())
            {
                _tree.resize(level);
            }

            if(_tree[level - 1].size() <= index+1)
            {
                _tree[level - 1].resize(index + 1);
            }
            int index1 = index * 2;
            int index2 = index1 + 1;
            
            if(level == 1)
            {
                updateLevelone(index,index1,index2);
            }
            else
            {
                updateLevel(level,index,index1,index2);
            }
        }
    }
    public:
    RangeMinimumQuery()
    {
    }
    push_back(const T &val)
    {
        _range.push_back(val);
        update(0,_range.size() -1);
    }
    void print()
    {
        for(int i = 0; i<_range.size();i++)
        {
            std::cout<<i<<"->"<<_range[i]<<std::endl;
        }
        for(int i = 0;i<_tree.size();i++)
        {
            int power = 1 << (i+1);
            for(int j = 0;j<_tree[i].size();j++)
            {
                int index1 = j*power;
                int index2 = index1 + power -1;
                
                if(index2 >= _range.size() )
                    index2 = _range.size() - 1;

                std::cout<<index1<<","
                    <<index2 - 1<<"->"
                    <<_range[_tree[j]]<<std::endl;
            }
        }
    }
};
#endif
