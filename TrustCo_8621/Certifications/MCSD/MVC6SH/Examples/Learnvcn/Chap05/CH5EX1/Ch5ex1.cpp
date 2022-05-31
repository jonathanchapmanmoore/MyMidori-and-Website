// ch5ex1.cpp
// For Try It Yourself, exercise 1, Chapter 5.
// Note: MFC has several much more robust array classes.
// You can more easily implement the same sort of queue from them.

#include <stdafx.h>
#include <iostream.h>
#include <assert.h>

const int ARRAY_MAX = 100;

class CArray
{
public:
CArray();
void SetAt(int nIndex, int nValue);
int GetAt(int nIndex);
	int GetCount();				// Actual elements in array
	int GetMaxSize();           // Max possible elements

// Implementation
private:
	int m_arInts[ARRAY_MAX];	// The underlying C++ array
	int m_nHiWaterMark;			// Highest array index assigned so far
};

class CQueue
{
public:
CQueue();
	void Add(int nValue);	    // At "tail" or "rear" of queue
	int Remove();			    // At "head" or "front" of queue
bool IsEmpty();
int GetCount();
int GetMaxSize();
int Peek();					    // Get value of item at head without 
								//  removing it

// Implementation
private:
	CArray arQueue;				// CQueue has-a CArray
	int head, tail;			    // Used to keep track of head and tail
	int m_nCount;				// Number of elements in queue currently
};


int main(int argc, char* argv[])
{
// Do some array operations
cout << "---- 1. Array operations ----------\n";
CArray ar;


// This loop puts the numbers 100 down to 0 into the array.  
for(int i = 0; i < ar.GetMaxSize(); i++)
	{
ar.SetAt(i, 100 - i);
	}


// This loop prints the numbers out: 100 down to 0 
for(int j = 0; j <= ar.GetCount(); j++)
	{
cout << ar.GetAt(j) << " ";
	}
cout << endl;


// Do some queue operations 
cout << "---- 2. Queue operations ----------\n";
CQueue q;


// This loop adds the numbers 0 through 99 to the 
//  rear of the queue (where all additions occur), 
//  but if k is even, we also remove the number at the 
//  front of the queue (where all removals occur).  
//  While it might seem we'd add only odd numbers to the 
//  queue, in fact we add the numbers 50 through 100.  
//  Since removal and addition don't occur at the same 
//  end of the queue, we aren't removing the number we 
//  just added.  
for(int k = 0; k < q.GetMaxSize(); k++)
	{
q.Add(k);
		if(k % 2 == 0)		// Every even k, do a Remove
			q.Remove();	
	}


// This loop outputs the queue's contents in ascending order 
//  (from front to rear).  
while(!q.IsEmpty())
	{
cout << q.Remove() << " ";
	}
cout << endl;
return 0;
}

////////////////////////////////////
// CArray implementation
CArray::CArray()
{
	// The high water mark tracks the highest array index 
	//  ever used.  
	m_nHiWaterMark = 0;
}

// SetAt stores nValue in array[nIndex].
void CArray::SetAt(int nIndex, int nValue)
{
	// Check that the index is in range.  
	assert(nIndex >= 0 && nIndex < ARRAY_MAX);

	// Add value to array at index.
	m_arInts[nIndex] = nValue;

	// Keep track of highest index used so far.
	// Increment only if new index is higher than any yet seen.  
	if(nIndex > m_nHiWaterMark)
	m_nHiWaterMark = nIndex;
}

// GetAt returns the value at array[nIndex].
int CArray::GetAt(int nIndex)
{
assert(nIndex >= 0 && nIndex < ARRAY_MAX);
return m_arInts[nIndex];
}

// GetCount returns the number of elements in use.
int CArray::GetCount()
{
// Number of in-use elements in array
return m_nHiWaterMark;
}

// GetMaxSize returns the number of possible elements.  
int CArray::GetMaxSize()
{
return ARRAY_MAX;
}

///////////////////////////////////
// CQueue implementation
CQueue::CQueue()
{
// Empty queue has head == tail
head = tail = 0;
// This count tracks number of elements added 
//  minus number removed.  
m_nCount = 0;
}

// Add stores nValue at the rear of the queue.
//  But if the queue fills up, we wrap around to the beginning 
//  of the underlying array if possible.  
void CQueue::Add(int nValue)
{
	// If queue grows too much, try to wrap around to beginning
	//   of the underlying array; fail if not possible
	if(tail >= arQueue.GetMaxSize())
	{
		// As elements are removed, the head moves along the
		//  underlying array, so it might be > 0.
		if(head > 0)
		{
			cout << "Queue wrapped around to beginning\n";
			cout << "Recommend removing some elements soon\n";
			tail = 0;			// Wrap around if room
			// Also wrap head around if it passes the end of the
			//  queue.
			if(head >= arQueue.GetMaxSize())
				head = 0;       
		}
		else
		{
			// Not a very robust queue, since it can't grow
			cout << "Queue overflowed\n";
			assert(0);			// No more room
		}
	}


	// Add the value to the tail of the queue
	arQueue.SetAt(tail, nValue);
	m_nCount++;
	tail++;
}

const int ERROR_QUEUE_EMPTY = -1;

// Remove the element at the head of the queue.
int CQueue::Remove()
{
	if(!IsEmpty())
	{
		int nResult = arQueue.GetAt(head);
		// Move head up one spot in the array.  
		head++; 
		m_nCount--; 
		return nResult;
	}
	else
	{
		cout << "Queue underflow: attempt to remove from empty queue\n"; 
		cout << "Recommend using IsEmpty before calling Remove\n"; 
		return ERROR_QUEUE_EMPTY;
	}
}

// IsEmpty returns true if the queue contains no elements.  
bool CQueue::IsEmpty()
{
	return (m_nCount < 1);
}

// GetCount returns the number of elements in the queue.  
int CQueue::GetCount()
{
	return m_nCount;
}

// GetMaxSize returns the possible number of elements in the queue.  
int CQueue::GetMaxSize()
{
	return arQueue.GetMaxSize();   // ARRAY_MAX
}

// Peek lets you see what's at the queue's head without removing 
//  the element there or altering the count of elements.  
int CQueue::Peek()
{
	// Examine value at head without removing it 
	return arQueue.GetAt(head);
}
