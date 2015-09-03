#include <bits/stdc++.h>
 
using namespace std;
int qu1[100000],indexl,indexr; 
// void printKMax(int arr[], int n, int k)
// {
 
//     std::deque<int>  Qi(k);
 
//     Qi.clear();
//     int i;
//     for (i = 1; i <= k; ++i)
//     {

//         while ( (!Qi.empty()) && arr[i] <= arr[Qi.back()])
//             Qi.pop_back();  
        
//         Qi.push_back(i);
//     }
 
//     for ( ; i <= n; ++i)
//     {

//         cout << arr[Qi.front()] << " ";
 
        
//         while ( (!Qi.empty()) && Qi.front() <= i - k)
//             Qi.pop_front();  
 
        
//         while ( (!Qi.empty()) && arr[i] <= arr[Qi.back()])
//             Qi.pop_back();
 
         
//         Qi.push_back(i);
//     }
//     // cout<<arr[Qi.front()]<<endl;
// }
void printKMax(int arr[], int n, int k)
{
 
    // std::deque<int>  Qi(k);
 
    
    int i;
    for (i = 1; i <= k; ++i)
    {

        while ( (indexl!=indexr) && arr[i] <= arr[qu1[indexr-1]])
            indexr--;  
        
        qu1[indexr++]=i;
    }
 
    for ( ; i <= n; ++i)
    {

        cout << arr[qu1[indexl]] << " ";
 
        
        while ( (indexl!=indexr) && qu1[indexl] <= i - k)
                indexl++; 
 
        
        while ( (indexl!=indexr) && arr[i] <= arr[qu1[indexr-1]])
                indexr--;
 
       
        qu1[indexr++]=i;  
    }
    // cout<<arr[Qi.front()]<<endl;
}
int main()
{
    int arr[] = {-98,1,3,13,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    printKMax(arr, n, k);
    indexl=indexr=0;
    k=3;    
    printKMax(arr, n, k);
    return 0;
}