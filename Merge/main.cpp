#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void MergeSort(vector<char>&);
void Divide(vector<char>&);
vector<char> Merge(vector<char>,vector<char>);

int main()
{
    srand(time(0));
    vector<char> Data;
    ostream_iterator<char> output (cout," ");//拿來輸出vector

    for(int i=0;i<10;i++)
    {
        Data.push_back('a' + (rand()%25));
    }
    cout<<"Unsort： ";
    copy(Data.begin(),Data.end(),output);
    cout<<endl;
    MergeSort(Data);
    cout<<"MergeSort: ";
    copy(Data.begin(),Data.end(),output);//輸出vector

    return 0;
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
