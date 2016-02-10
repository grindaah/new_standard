#pragma once
typedef bool (List::*PF)(const Node* fNode, const Node* sNode) const; // <PF> is a pointer to comparison function
enum SORT_ATTR{SQUARE, COLOR, REMOTENESS};

class List
{
	size_t m_size;
	Node Head,Tail;

	PF m_pf; // pointer to the certain comparison function (set by SORT_ATTR parameter in SelectionSort)
	bool HasGreaterSquare(const Node* fNode, const Node* sNode) const; // compare squares of Shapes in the Nodes
	bool HasGreaterColor(const Node* fNode, const Node* sNode) const; // compare colors of Shapes in the Nodes
	bool IsMoreRemote(const Node* fNode, const Node* sNode) const; // compare remoteness of Shapes in the Nodes from (0;0)
	Node* FindMinNode(Node* cur) const; // return minimal Node in the List beginning from Node <cur> inclusively
		
	void Print(ostream&) const;
	void Read(istream&);
public:
	List(void);	 // create an empty List (Head and Tail point to each other)
	List(const List&);
	List(List&&);

	~List(void);

	List& operator=(const List&);
	List& operator=(List&&);

	void AddToHead(Shape*);
	void AddToTail(Shape*);
	bool RemoveFirst(const Shape& c); // remove the first Node pointed to Shape <c>
	size_t Remove(const Shape& c); // remove all Nodes pointed to Shape <c>; return number of removed Nodes
	void Clear(); // clear List
	void SelectionSort(SORT_ATTR); // sort by ascending of sorting attribute


	friend ostream& operator<<(ostream&,const List&);
	friend istream& operator>>(istream&,List&);
};

