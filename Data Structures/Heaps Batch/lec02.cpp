/*
Heap 

Heap is visualize as a complete binary tree (CBT) but in code it is written as vector or array.
The heap visualized in CBT must satify two conditions :
    (i).  CBT is a BT where all the levels are filled except maybe the last one, which is filled 
          from left to right 
    (ii). Also for MAX heap : parent >= children  always 

NOTE :: Priority Queue is a implementation of heaps & heaps are implementation of arrays/vectors

Why not to use Trees for code of heaps ?
because to insert a new value in the heap we require o(n) time where n is the no. of nodes in 
tree.. which further require to rebalance the CBT as per the property 2 ( if required )

Then how using vector it resolves the time complexity problem ?
basically we can represnt a CBT in array/vector by two ways based on indexing :
    (i).  0 Based Indexing 
    (ii). 1 Based Index

The vector representation of any CBT is very simple it is just level order traversing of 
the Tree and then assigning them to array/vector.

For 0 Based Indexing : 
If parent node have the index i then for left child index formula used : idx = 2*i + 1
If parent node have the index i then for right child index formula used : idx = 2*i + 2
If child node have index i then for parent : idx = (i-1)/2
                
For 1 Based Indexing : 
If parent node have the index i then for left child index formula used : idx = 2*i 
If parent node have the index i then for right child index formula used : idx = 2*i + 1
If child node have index i then for parent : idx = i/2 

Now if any new element is needed to add on heaps , then it is just pushed into vector by
push() which is just o(1) operation , and further some operation required to rebalance the
CBT but still o(n) time complexity saves to o(1) 
Therefore , we use heaps implemented by array/vector

*/



