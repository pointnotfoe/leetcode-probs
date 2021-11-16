/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/median-of-two-sorted-arrays/#
-------------
 sudo apt-get install gdb
   21  sudo apt-get update
   22  cd testing/
   23  gdb ./median
   24  sudo apt-get install gdb
   25  gdb ./median
   26  g++ -std=c++11 two_sorted_arr_median.cpp -o median
   27  apt-get install eglibc-source
   28  sudo apt-get install eglibc-source
   29  ls /usr/src/glibc/eglibc-2.11.1/elf
   30  ls /usr/src/glibc/
   31  tar -xvf /usr/src/glibc/eglibc-2.19.tar.xz
   32  ls /usr/src/glibc/
   33  ls
   34  ls eglibc-2.19/
   35  mv eglibc-2.19 /usr/src/glibc/eglibc-2.19
   36  sudo mv eglibc-2.19 /usr/src/glibc/eglibc-2.19
   37  gdb ./median
   38  echo "directory /usr/src/glibc/eglibc-2.19/elf" >> ~/.gdbinit
   39  gdb ./median
   40  g++ -g -std=c++11 two_sorted_arr_median.cpp -o median
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;
                       

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        
        std::map<int,int> merge_map;
        //Add arrays to map and count up repetitions
        int m = nums1.size();
        for (int i = 0; i < m; i++)
        {
            merge_map[nums1[i]]++;
        }
        
        int n = nums2.size();
        for (int i = 0; i < n; i++)
        {
            merge_map[nums2[i]]++;
        }
        
        int total_size = m + n;
        int merge_arr[total_size];
        int index = 0;
        for (std::map<int,int>::iterator it=merge_map.begin(); it!=merge_map.end(); ++it)
        {
            for(int i = 0; i < it->second; i++)
            {
                merge_arr[index++] = it->first;
            }
        }
          //std::cout << it->first << " => " << it->second << '\n';
        
        
        int mid = total_size/2;
        if ((total_size%2) != 0)//if odd 
        {
            return merge_arr[mid];//get the mid one
        }
        else//even
        {
            return (merge_arr[mid - 1] + merge_arr[mid])/2.0;//get the average of the two centre elements
        }
    }
};

int main()
{
    Solution median;
    vector<int> test_data1 {1,2,3,10,50,78,6};
    vector<int> test_data2 {13,10,56};

    cout << "vec1:";
    for (int i = 0; i < test_data1.size(); i++)
    {
        cout << test_data1[i] << " ";                                                                                    
	}
    cout << endl<< " and vect2: ";
    for (int i = 0; i < test_data2.size(); i++)
    {
        cout << test_data2[i] << " ";
    }


    cout << endl<< "Median = " << median.findMedianSortedArrays(test_data1, test_data2) << endl;                     
    return 0;

}