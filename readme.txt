Heap for Priority Queues :
Priority Queues are queues with priorities. High priority elements are dequeued first. Heaps are very efficient way of 
implementing the Priority Queues as they support all the following mentioned operations very effectively.
Implementation:
1.I used Min-Heap as a data structure to implement the Priority Queue.
2.I created a Dictionary whose key is priority and value is data.
3.The priorities are sorted using HeapSort which results in sorted dictionary(Keys in sorted order)
4.Insert: while inserting an element the heap property is maintained.
5.All-Minimum : I found the element with highest priority(least value of key). Then I returned all the elements with the key.
6.Decrease-key: I updated the priority value of the element with the new key and restored the heap property.
7.Extract-all-min: I found the element with highest priority(least value of key). I returned all the elements with the key.
				   Then I heapified the heap to restore the heap property.
				   
I used the following reference document to implement:
http://pages.cs.wisc.edu/~vernon/cs367/notes/11.PRIORITY-Q.html

				   
				   
Smooth Sort:
Smooth sort is an adaptive sort which runs in O(n) when the elements are in some what sorted order.
The heapsort is tweaked a bit to implement the Smooth sort. Every time we build a heap, the max element is on the left side and
we have to swap it with the right most element. With the help of Smooth sort, we manage to get the largest element on the right side as
Leonardo heap roots are always in the descending order.
Implementation:
1.I built a class called LeonardoNumber which is used to build Leonardo trees.
2. A leonardo forest is built which contains multiple heaps.
3. The sequence order of the leonardo forest(All the roots of the heaps should be in Descending order)
	is maintained using Insertion sort.
4. The heap property of each heap is maintained using Heapify function which is similar to the one used
   in the Heap for Priority Queues.
   
I used the following reference document to implement:
http://www.keithschwarz.com/smoothsort/