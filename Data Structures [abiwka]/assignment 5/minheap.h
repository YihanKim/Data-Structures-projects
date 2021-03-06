#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>

/**
 * Assignment 5 for CSE221 Data Structures
 *
 * 2015. 11. 2
 *
 */


// Heap element
class heapElem
{
public:
	double dist;       // shortest path distance
	unsigned int vidx; // vertex index

    ~heapElem () {
    }
    heapElem () {
    };
    heapElem (unsigned int i, double d) {
        dist = d;
        vidx = i;
    }
    bool operator < (heapElem b) {
        return dist < b.dist;
    }
    bool operator > (heapElem b) {
        return dist > b.dist;
    }
    bool operator >= (heapElem b) {
        return dist >= b.dist;
    }
    bool operator <= (heapElem b) {
        return dist <= b.dist;
    }
    bool operator == (heapElem b) {
        return dist == b.dist;
    }
    bool operator != (heapElem b) {
        return dist != b.dist;
    }
};


// MinHeap class
class MinHeap {
public:
	MinHeap(unsigned int maxheapsize)
	{
		size = 0;      // current heap size
		capacity = maxheapsize; // maximum heap capacity
		heapArray = new heapElem[capacity+1]; // first element is stored in heapElem[1]
		mapVidxToArray = new unsigned int[capacity];
		for(int i=0; i<capacity; i++) mapVidxToArray[i] = 0; // new init
	};

	~MinHeap();

	void PushUp (unsigned int k);

	void PushDown (unsigned int k);

	void Push(const heapElem& e);

	const heapElem & Top();

	void Pop();

	void Modify(const heapElem& e);

	bool IsEmpty();

	bool NotEmpty();

	// new function
	bool IsInHeap(const heapElem& e) {
		if(mapVidxToArray[e.vidx] == 0) return false;
		return true;
	};

private:
	heapElem* heapArray;
	unsigned int* mapVidxToArray; // map between vertex index to heapArray
	unsigned int capacity, size;
};

#endif
