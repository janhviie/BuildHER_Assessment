# BuildHER_Assessment
Coding assessment Questions for BuildHER Internship program

1. EASY question -
  Problem Statement - Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
  
  Approach -:
  1. Find the middle element of the array.
  2. Create a new node with the value of the middle element.
  3. Recursively repeat steps 1 and 2 with the left half of the array to create the left subtree of the new node.
  4. Recursively repeat steps 1 and 2 with the right half of the array to create the right subtree of the new node.
  5. Return the new node.
  
2. MEDIUM question -
   Problem Statement - Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
   
   Approach -:
   1. Start from the root node of the BST.
   2. If the value of the root node is greater than both the nodes, then the LCA lies in the left subtree. Recursively search for the LCA in the left subtree.
   3. If the value of the root node is smaller than both the nodes, then the LCA lies in the right subtree. Recursively search for the LCA in the right subtree.
   4. If neither of the above cases is true, then the root node is the LCA.
   
   
   Problem Statement - Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
   
   Approach -:
   The DP approach involves creating a new matrix dp with the same dimensions as the input matrix, where dp[i][j] represents the length of the side of the largest square    that can be formed with the bottom right corner at position (i, j) in the input matrix. dp[i][j] is calculated by looking at the values of dp[i-1][j], dp[i][j-1], and    dp[i-1][j-1]
   
3. HARD question -
   Problem Statement - Return the max sliding window given an array.
   
   Approach -:
   Approach to solve this problem is to use a deque (double-ended queue).
   The idea is to maintain a deque that stores indices of elements in the current window, with the maximum element at the front of the deque. At each step, next element is added to the back of the deque, and any indices from the front of the deque are removed that are outside the current window. indices at the back of the deque that have values less than or equal to the value of the new element are also removed, since they are no longer relevant as potential maximums for future windows.
   The front of the deque always stores the maximum element for the current window. This is appended to the result array.
