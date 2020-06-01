/*

First Unique Number
Solution
You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.
 

Example 1:

Input: 
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output: 
[null,2,null,2,null,3,null,-1]

Explanation: 
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1

Example 2:

Input: 
["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
[[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
Output: 
[null,-1,null,null,null,null,null,17]

Explanation: 
FirstUnique firstUnique = new FirstUnique([7,7,7,7,7,7]);
firstUnique.showFirstUnique(); // return -1
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
firstUnique.add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
firstUnique.showFirstUnique(); // return 17

Example 3:

Input: 
["FirstUnique","showFirstUnique","add","showFirstUnique"]
[[[809]],[],[809],[]]
Output: 
[null,809,null,-1]

Explanation: 
FirstUnique firstUnique = new FirstUnique([809]);
firstUnique.showFirstUnique(); // return 809
firstUnique.add(809);          // the queue is now [809,809]
firstUnique.showFirstUnique(); // return -1
Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^8
1 <= value <= 10^8
At most 50000 calls will be made to showFirstUnique and add.

*/

class FirstUnique {
public:
    unordered_map<int,list<int>::iterator> map_to_list;
    list<int> unique_elements;
    list<int> non_unique_elements;
    
    FirstUnique(vector<int>& nums) {
        non_unique_elements.push_back(-1);
        for(int i = 0; i < nums.size(); i++){
            if(map_to_list.find(nums[i]) == map_to_list.end()){
                unique_elements.push_front(nums[i]);
                map_to_list[nums[i]] = unique_elements.begin();
            }
            else{
                auto it = map_to_list[nums[i]];
                if(it != non_unique_elements.begin()){
                    unique_elements.erase(it);
                    map_to_list[nums[i]] = non_unique_elements.begin();
                }
            }
        }
    }
    
    int showFirstUnique() {
        if(unique_elements.size() == 0)
            return -1;
        else{
            return unique_elements.back();
        }
    }
    
    void add(int value) {
        if(map_to_list.find(value) == map_to_list.end()){
            unique_elements.push_front(value);
            map_to_list[value] = unique_elements.begin();
        }
        else{
            auto it = map_to_list[value];
            if(it != non_unique_elements.begin()){
                unique_elements.erase(it);
                map_to_list[value] = non_unique_elements.begin();
            }
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

