#ifndef SORT_H_
#define SORT_H_
#include <string>
#include <vector>
using namespace std;
//Sorting-Algorithm.H

void BubleSort(string&);
void InsertSort(string&);
void QuickSort(string&,int,int);
void MergeSort(vector<char>&);
void Divide(vector<char>&);
vector<char> Merge(vector<char>,vector<char>);
vector<int> CountingSort(vector<int>);
vector<int> BucketSort(vector<int>);
void RadixSort(vector<string>&,int);

#endif // SORT_H_
