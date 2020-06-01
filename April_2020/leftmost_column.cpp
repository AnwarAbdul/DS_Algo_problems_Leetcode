/*
Leftmost Column with at Least a One
Solution
(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

 

 

 

Example 1:



Input: mat = [[0,0],[1,1]]
Output: 0
Example 2:



Input: mat = [[0,0],[0,1]]
Output: 1
Example 3:



Input: mat = [[0,0],[0,0]]
Output: -1
Example 4:



Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1
 

Constraints:

rows == mat.length
cols == mat[i].length
1 <= rows, cols <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in a non-decreasing way.

*/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

int binary_search(BinaryMatrix &binaryMatrix, int row, int low, int high, int cols){
    if(low > high)
        return -1;
    int mid = low + (high - low)/2;
    if(binaryMatrix.get(row,mid) == 1){
        if(low == mid)
            return mid;
        else
            return binary_search(binaryMatrix,row,low,mid,cols);
    }
    else{
        if(mid == high)
            return -1;
        else
            return binary_search(binaryMatrix,row,mid+1,high,cols);
    }
}


class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int rows = dimensions[0];
        int cols = dimensions[1];
        int pos = -1;
        int earliest = -1;
        for(int i = 0; i < rows; i++){
            pos = binary_search(binaryMatrix,i,0,cols-1,cols);
            if(pos != -1){
                if(earliest == -1)
                    earliest = pos;
                else{
                    if(pos < earliest)
                        earliest = pos;
                }
            }
        }
        return earliest;
    }
};