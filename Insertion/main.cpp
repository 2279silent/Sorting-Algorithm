#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void InsertSort(string&);
int main()
{
    srand(time(0));
    string Data;
    cout<<Data<<endl;
    for(int i=0;i<5;i++)
        Data += 'a' + (rand()%25);
    cout<<"未排序: "<<Data<<endl;
    InsertSort(Data);
    cout<<"排序: "<<Data<<endl;

    return 0;
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
        cout<<Data<<endl;
    }
}

