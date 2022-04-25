/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    int next_val;
    bool iter_hasnext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) 
    {
        iter_hasnext=Iterator::hasNext();
	    if (iter_hasnext)
      next_val = Iterator::next();
	}
	
	int peek() 
    {
        return next_val;
	}
	
	int next() 
    {
	    int curr_next = next_val;
        iter_hasnext=Iterator::hasNext();
	    if (iter_hasnext) 
        next_val = Iterator::next();
        
	    return curr_next;
	}
	
	bool hasNext() const 
    {
	    return iter_hasnext;
	}
};
