#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void BubleSort(int*);
void BubleSort(string&);

int main()
{
    srand(time(0));
    int* Data = new int(0);
    string Str = " ";
    int i = -1;
    cout << "�H���@��Ʀr" << '\n';
    while(i<10)
    {
        i++;
        *(Data+i) = rand()%100;
        cout << *(Data+i) << " ";
    }
    *(Data+i+1) = '\n';

    BubleSort(Data);//�w�j�Ƨ�
    cout.put('\n');
    for(int k=0;*(Data+k)!= 10;k++)//��X�Ƨǵ��G
        cout << *(Data+k) << " ";

    cout <<'\n' << "��J�@��^��r" << '\n';//Ū���r��

    getline(cin,Str);
    BubleSort(Str);
    cout << Str;
    system("pause");
    return 0;
}

void BubleSort(string& SortD)
{
    string::iterator Index;
    while(Index!=SortD.end())
    {
        for(string::iterator i=SortD.begin();(i+1)!=SortD.end();i++)
        {
            if( *i > *(i+1))
                swap(*i,*(i+1));
        }
        Index++;
    }
}
void BubleSort(int* SortD)
{
    int Index = 0;
    while((char)*(SortD+Index)!='\n')
    {
        for(int i=0;(char)*(SortD+i+1)!='\n';i++)
        {
            if(*(SortD+i) > *(SortD+i+1))
                swap(*(SortD+i),*(SortD+i+1));
        }
        Index++;
    }
}
