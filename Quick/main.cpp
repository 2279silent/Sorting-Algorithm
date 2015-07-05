#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void QuickSort(string&,int,int);
int main()
{
    srand(time(0));
    string Data;

    for(int i=0;i<10;i++)
        Data += 'a' + (rand()%25);

    cout<<"未排序： "<<Data<<endl;
    QuickSort(Data,0,(Data.size()-1));
    cout<<"排序: "<<Data<<endl;
    system("PAUSE");
    return 0;
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
