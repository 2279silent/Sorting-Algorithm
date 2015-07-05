#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
ostream_iterator<int> output (cout," ");
void RadixSort(vector<string>&,int);

int main()
{
    srand(time(0));
    vector<string> Data;
    int Digit =0;

    for(int i=0;i<10;i++)//產生字串
    {
        string TempC;
        for(int c=0;c<5;c++)
            TempC += ('a'+(rand()%26));
        Data.push_back(TempC);
    }

    cout<<"Unsort";
    for(int i=0;i<Data.size();i++)
        cout<<endl<<right<<Data[i];


    for(auto i:Data)//算出有幾個字串
        if(i.size()>Digit)
            Digit=i.size();

    RadixSort(Data,Digit);

    cout<<endl<<"Radixsort";
    for(int i=0;i<Data.size();i++)
        cout<<endl<<right<<Data[i];

    return 0;
}

void RadixSort(vector<string>& Data,int Digit)
{
    for(int D=Digit-1;D>=0;D--)
    {
    vector<vector<string>> Bucket;
    vector<string> Zero;

    Bucket.assign(26,Zero);//動態配置空間

    for(auto i:Data)//把要排序的數字放到對應的籃子裡  e.g.:數字20會被放到Bucket[20]
       Bucket[(int)i[D]-97].push_back(i);

    Data.clear();

    for(auto Sorted:Bucket)//由小到大從籃子裡把數字拿出來
       Data.insert(Data.end(),Sorted.begin(),Sorted.end());

    }
}
