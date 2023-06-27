#include <iostream>
using namespace std;

int binarySearch(int ar[],int size,int key)//algo
{
 int low=0;
 int high=size-1;
 int  mid;
 
 while(low<=high)
 {
   mid=(low+high)/2;
   
   if(ar[mid]==key){
     return mid;
   }
   
   //go to right part
   if(key>ar[mid])
    low=mid+1;
    
   // goto left part 
   else
    high=mid-1;
    
 }return -1;
}

int main() 
{
   int ar[]={1,4,5,9,11,23,25}; // elements must be in sorted order for binary search
   int size=sizeof(ar)/sizeof(ar[0]);
   int key=11;//take any key from array
   
  int val=binarySearch(ar,size,key);
  
  if(val==-1)
   cout<<"Not found";
  else
   cout<<"Found at index: "<<val;
   
    return 0;
}

//Time Complexity= n+ n/2 + n/4 +...+2+1== O(log n)
//Space  complexity =constant array and variables== O(1)
