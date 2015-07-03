#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
ostream_iterator<int> output (cout," ");
vector<int> CountingSort(vector<int>);
int main()
{
    srand(time(0));
    vector<int> Data;//拿來輸出vector

    for(int i=0;i<10;i++)
    {
        Data.push_back((rand()%10));
    }
    cout<<"Unsort： ";
    copy(Data.begin(),Data.end(),output);
    cout<<endl;
    Data=CountingSort(Data);
    cout<<"CountingSort: ";
    copy(Data.begin(),Data.end(),output);//輸出vector

    return 0;
}

vector<int> CountingSort(vector<int> UnSortingData)
{
    vector<int> Counting;
    vector<int> SortingData(UnSortingData.size(),0);
    int T = UnSortingData.front();

    for(auto i = UnSortingData.begin();i!=UnSortingData.end();i++)//取最大的數字當向量長度
    {
        if(T<*i)
            T=*i;
    }
    Counting.assign(T+1,0);//動態配置空間

    for(auto i:UnSortingData)//計算每個數字的數量
        Counting[i]++;
    for(auto CountingI=Counting.begin()+1;CountingI!=Counting.end();CountingI++)//計算順序
        *CountingI += *(CountingI-1);
    for(auto SortingI:UnSortingData)//排序
    {
        SortingData[Counting[SortingI]-1] = SortingI;
        Counting[SortingI]--;
    }

    return SortingData;
}
