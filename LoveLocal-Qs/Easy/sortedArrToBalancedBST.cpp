#include<bits/stdc++.h>
using namespace std;

// EASY 2
// Question - Given an integer array nums where the elements are sorted in ascending order, convert it to a 
// height-balanced binary search tree.

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

Node* ArrToBST(int start, int end, vector<int>& arr)
{
    if(start > end){return NULL;}

    int mid = (start + end)/2;
    Node* newnode = new Node(arr[mid]);

    // recursively calling for finding left and right nodes

    newnode->left = ArrToBST(start, mid-1, arr);
    newnode->right = ArrToBST(mid+1, end, arr);

    return newnode;
}

int main()
{
    // Input Format -:
    // First Line consisting of N - the length of array 
    // Second Line - N space-separated integers, the elements of the array 

    int N=0;
    cin>>N;

    vector<int> arr;

    int len = N;

    while(len--)
    {
        int elem=0;
        cin>>elem;
        arr.push_back(elem);
    }
    cout<<endl;

    // func ArrToBST returns the root node of the Balanced BST

    Node* root = ArrToBST(0, N-1, arr);

}

// TIME COMPLEXITY - O(N) where N is length of array
// SPACE COMPLEXITY - O(H) Where H is height of the tree