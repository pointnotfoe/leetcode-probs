/* https://leetcode.com/problems/maximum-units-on-a-truck/description/?envType=problem-list-v2&envId=7p5x763&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1
1710. Maximum Units on a Truck
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

 

Example 1:

Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
Example 2:

Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91
 

Constraints:

1 <= boxTypes.length <= 1000
1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
1 <= truckSize <= 106

Runtime 11 ms Beats 28.30% 
Memory 21.56 MB Beats 21.72%
*/
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        map<int, int> unit_box_map;
        for (auto &b: boxTypes)
        {
            unit_box_map[b[1]] += b[0];
        }
        int res = 0;
        int boxes;
        for (auto itr = unit_box_map.rbegin(); truckSize > 0 && itr != unit_box_map.rend(); itr++)
        {
            boxes = min(itr->second, truckSize);
            res += (boxes * itr->first);
            truckSize -= boxes;
        }
        return res;
    }
};