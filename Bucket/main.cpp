#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
ostream_iterator<int> output (cout," ");
vector<int> BucketSort(vector<int>);
int main()
{
    srand(time(0));
    vector<int> Data;//拿來輸出vector

    for(int i=0;i<10;i++)
    {
        Data.push_back((rand()%25));
    }
    cout<<"Unsort： ";
    copy(Data.begin(),Data.end(),output);
    cout<<endl;
    Data=BucketSort(Data);
    cout<<"BucketSort: ";
    copy(Data.begin(),Data.end(),output);//輸出vector

    return 0;
}

vector<int> BucketSort(vector<int> UnSortedData)
{
    vector<vector<int>> Bucket;
    vector<int> Zero;
    vector<int> SortedData;
    int T = UnSortedData.front();

    for(auto i = UnSortedData.begin();i!=UnSortedData.end();i++)//取最大的數字當向量長度
    {
        if(T<*i)
            T=*i;
    }
    Bucket.assign(T+1,Zero);//動態配置空間
    for(auto i:UnSortedData)
        Bucket[i].push_back(i);
    for(auto Sorted:Bucket)
        SortedData.insert(SortedData.end(),Sorted.begin(),Sorted.end());

    return SortedData;
}
