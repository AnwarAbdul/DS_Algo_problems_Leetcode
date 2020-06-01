/*
Given an integer array arr, count element x such that x + 1 is also in arr.

If there're duplicates in arr, count them seperately.

 

Example 1:

Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
Example 2:

Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.
Example 3:

Input: arr = [1,3,2,3,5,0]
Output: 3
Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.
Example 4:

Input: arr = [1,1,2,2]
Output: 2
Explanation: Two 1s are counted cause 2 is in arr.
 

Constraints:

1 <= arr.length <= 1000
0 <= arr[i] <= 1000*/
class Solution {
public:
    
    int count_instances(vector<int> arr, int index, int low, int high, int key){
        int instances = 0;
        int temp = index;
        while(--temp >= low){
            if(arr[temp] != key)
                break;
            else
                instances++;
        }
        temp = index;
        while(++temp <= high){
            if(arr[temp] != key)
                break;
            else 
                instances++;
        }
        return ++instances;
    }
    
    
    int countElements(vector<int>& arr) {
        unordered_set<int> unique_elements;
        int i;
        for(i = 0; i < arr.size(); i++){
            if(unique_elements.find(arr[i]) != unique_elements.end())
               continue;
            else
                unique_elements.insert(arr[i]);
        }
        vector<int> unique_elements_vector(unique_elements.begin(), unique_elements.end());
        sort(unique_elements_vector.begin(), unique_elements_vector.end());
        sort(arr.begin(),arr.end());
        vector<int> instances_unique_elements;
        int index;
        for(i = 0; i < unique_elements_vector.size(); i++){
            instances_unique_elements.push_back(0);
            index = binary_search(arr,0,arr.size()-1,unique_elements_vector[i]);
            instances_unique_elements[i] = count_instances(arr,index,0,arr.size()-1,unique_elements_vector[i]);
        }
        int count;
        count = 0;
        int instances;
        for(i = 0; i < unique_elements_vector.size(); i++){
            
            if(unique_elements.find(unique_elements_vector[i]+1) != unique_elements.end())
                count += instances_unique_elements[i];
            
        }
        return count;
    }
};