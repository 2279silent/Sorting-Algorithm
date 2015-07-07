#include <iterator>
#include <vector>
#include <string>
#include "Sort-Algorithm.h"
using namespace std;
void BubleSort(string& Data)
{
    string::iterator Index;
    while(Index!=Data.end())
    {
        for(string::iterator i=Data.begin();(i+1)!=Data.end();i++)
        {
            if( *i > *(i+1))
                swap(*i,*(i+1));
        }
        Index++;
    }
}

void InsertSort(string& Data)
{
    for(string::iterator UnSort = Data.begin()+1;UnSort!=Data.end();UnSort++)
    {
        char T =(char)*UnSort;
        string::iterator Sort =UnSort-1;
        for(Sort;Sort!=(Data.begin()-1);Sort--)
        {
            if(*Sort>=T)
                *(Sort+1) = *Sort;
            else
                {
                    break;
                }
        }
        *(Sort+1) = T;
    }
}

void MergeSort(vector<char>& Data)
{
    if(Data.size()<=1)
        return;
    Divide(Data);
}

void Divide(vector<char>& Data)
{
    if(Data.size()<=1)
        return;

    auto Mid = Data.begin()+(Data.size()/2);
    vector<char> Left(Data.begin(),Mid);
    vector<char> Right(Mid,Data.end());

    Divide(Left);
    Divide(Right);
    Data=Merge(Left,Right);
}

vector<char> Merge(vector<char> Left,vector<char> Right)
{
    vector<char> Merge;
    auto L = Left.begin();
    auto R = Right.begin();

    while(L!=Left.end() && R!=Right.end())
    {
        if(*L < *R)
        {
            Merge.push_back(*L);
            L++;
        }
        else
        {
            Merge.push_back(*R);
            R++;
        }
    }
    if(L==Left.end())
    {
        Merge.insert(Merge.end(),R,Right.end());
        return Merge;
    }
    else if(R==Right.end())
    {
        Merge.insert(Merge.end(),L,Left.end());
        return Merge;
    }
}

void QuickSort(string& Data,int Front,int Rear)
{
    if(Front>Rear)
    {
        return;
    }
    char T = Data[Front];
    int  PivotIndex = Front+1;
    for(int i=Front;i<=Rear;i++)
    {
        if(Data[i]<T)
        {
            swap(Data[PivotIndex],Data[i]);
            PivotIndex++;
        }
    }
    swap(Data[Front],Data[PivotIndex-1]);
    QuickSort(Data,Front,PivotIndex-2);
    QuickSort(Data,PivotIndex,Rear);
}

vector<int> CountingSort(vector<int> UnSortingData)
{
    vector<int> Counting;
    vector<int> SortingData(UnSortingData.size(),0);
    int T = UnSortingData.front();

    for(auto i = UnSortingData.begin();i!=UnSortingData.end();i++)//���̤j���Ʀr��V�q����
    {
        if(T<*i)
            T=*i;
    }
    Counting.assign(T+1,0);//�ʺA�t�m�Ŷ�

    for(auto i:UnSortingData)//�p��C�ӼƦr���ƶq
        Counting[i]++;
    for(auto CountingI=Counting.begin()+1;CountingI!=Counting.end();CountingI++)//�p�ⶶ��
        *CountingI += *(CountingI-1);
    for(auto SortingI:UnSortingData)//�Ƨ�
    {
        SortingData[Counting[SortingI]-1] = SortingI;
        Counting[SortingI]--;
    }

    return SortingData;
}

vector<int> BucketSort(vector<int> UnSortedData)
{
    vector<vector<int>> Bucket;
    vector<int> Zero;
    vector<int> SortedData;
    int T = UnSortedData.front();

    for(auto i = UnSortedData.begin();i!=UnSortedData.end();i++)//���̤j���Ʀr��V�q����
    {
        if(T<*i)
            T=*i;
    }
    Bucket.assign(T+1,Zero);//�ʺA�t�m�Ŷ�

    for(auto i:UnSortedData)//��n�ƧǪ��Ʀr���������x�l��  e.g.:�Ʀr20�|�Q���Bucket[20]
        Bucket[i].push_back(i);
    for(auto Sorted:Bucket)//�Ѥp��j�q�x�l�̧�Ʀr���X��
        SortedData.insert(SortedData.end(),Sorted.begin(),Sorted.end());

    return SortedData;
}

void RadixSort(vector<string>& Data,int Digit)
{
    for(int D=Digit-1;D>=0;D--)
    {
    vector<vector<string>> Bucket;
    vector<string> Zero;

    Bucket.assign(26,Zero);//�ʺA�t�m�Ŷ�

    for(auto i:Data)//��n�ƧǪ��Ʀr���������x�l��  e.g.:�Ʀr20�|�Q���Bucket[20]
       Bucket[(int)i[D]-97].push_back(i);

    Data.clear();

    for(auto Sorted:Bucket)//�Ѥp��j�q�x�l�̧�Ʀr���X��
       Data.insert(Data.end(),Sorted.begin(),Sorted.end());

    }
}
