#include <iostream>
#include <iterator>
#include <algorithm>
#include "Sort-Algorithm.h"
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
    srand(time(0));
    string OriginalData;
    string S_Data;
    vector<char> C_Data;
    vector<string> String_Data;
    vector<int> I1_Data;
    vector<int> I2_Data;
    ostream_iterator<char> output (cout," ");//拿來輸出vector

    for(int i=0;i<25;i++)
    {
        char Word;
        Word = 'A' + (rand()%25);
        OriginalData.push_back(Word);
        I1_Data.push_back((int)Word);
        I2_Data.push_back((int)Word);
    }

    cout<<"隨機產生的一串字母：";
    copy(OriginalData.begin(),OriginalData.end(),output);
    cout<<endl<<endl;

    {
        clock_t T1,T2;
        T1 = clock();

        S_Data = OriginalData;
        BubleSort(S_Data);
        cout<<"BubleSort";
        copy(S_Data.begin(),S_Data.end(),output);
        T2 = clock();
        cout<<endl<<"排序時間："<<T2-T1<<"ms"<<endl<<endl;
    }

    {
        clock_t T1,T2;
        T1 = clock();

        S_Data = OriginalData;
        InsertSort(S_Data);
        cout<<"InsertSort:";
        copy(S_Data.begin(),S_Data.end(),output);
        T2 = clock();
        cout<<endl<<"排序時間："<<T2-T1<<"ms"<<endl<<endl;
    }

    {
        clock_t T1,T2;
        T1 = clock();

        S_Data = OriginalData;
        QuickSort(S_Data,0,S_Data.size()-1);
        cout<<"QuickSort:";
        copy(S_Data.begin(),S_Data.end(),output);
        T2 = clock();
        cout<<endl<<"排序時間："<<T2-T1<<"ms"<<endl<<endl;
    }

    {
        clock_t T1,T2;
        T1 = clock();

        C_Data.assign(OriginalData.begin(),OriginalData.end());
        MergeSort(C_Data);
        cout<<"MergeSort:";
        copy(C_Data.begin(),C_Data.end(),output);
        T2 = clock();
        cout<<endl<<"排序時間："<<T2-T1<<"ms"<<endl<<endl;
    }

    {
        clock_t T1,T2;
        T1 = clock();

        I1_Data=CountingSort(I1_Data);
        cout<<"CountingSort:";
        copy(I1_Data.begin(),I1_Data.end(),output);
        T2 = clock();
        cout<<endl<<"排序時間："<<T2-T1<<"ms"<<endl<<endl;
    }

    {
        clock_t T1,T2;
        T1 = clock();

        I2_Data=BucketSort(I2_Data);
        cout<<"BucketSort:";
        copy(I2_Data.begin(),I2_Data.end(),output);
        T2 = clock();
        cout<<endl<<"排序時間："<<T2-T1<<"ms"<<endl<<endl;
    }

    {
        clock_t T1,T2;
        T1 = clock();
        int Digit = 0;

        for(int i=0;i<10;i++)//產生字串
        {
            string TempC;
            for(int c=0;c<5;c++)
                TempC += ('a'+(rand()%26));
            String_Data.push_back(TempC);
        }

        for(auto i:String_Data)//算出有幾個字串
            if(i.size()>Digit)
                Digit=i.size();

        RadixSort(String_Data,Digit);

        cout<<"RadixSort:";
        cout<<String_Data[0]<<endl;
        for(int i=1;i<String_Data.size();i++)
        cout<<right<<setw(15)<<String_Data[i]<<endl;
        T2 = clock();
        cout<<"排序時間："<<T2-T1<<"ms"<<endl;
    }
    system("PAUSE");
}
