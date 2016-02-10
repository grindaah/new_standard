#include "stdafx.h"
#include "List.h"


List::List(void)
{
    m_size=0;
    Head.pNext=&Tail;
    Tail.pPrev=&Head;
    // For the sake of correct call of ~Node():
    Head.m_Data=nullptr;
    Tail.m_Data=nullptr;
}


List::~List(void)
{
    Clear();
}

void List::AddToHead(Shape* c)
{
    new Node(&Head,c);
    m_size++;
}

void List::AddToTail(Shape* c)
{
    new Node(Tail.pPrev,c);
    m_size++;
}

bool List::RemoveFirst(const Shape& c)
{
    Node* p=Head.pNext;
    while(p!=&Tail)
    {
        if(*p->m_Data==c)
        {
            delete p;
            m_size--;
            return true;
        }
        p=p->pNext;
    }
    return false;
}

size_t List::Remove(const Shape& c)
{
    size_t count=0;
    Node* p=Head.pNext;
    while(p!=&Tail)
    {
        Node* n=p->pNext;
        if(*p->m_Data==c)
        {
            count++;
            delete p;
            m_size--;
        }
        p=n;
    }

    return count;
}

void List::Clear()
    // clear List
{
    while(Head.pNext!=&Tail)
        delete Head.pNext; // call destructor for current Node
}

void List::SelectionSort(/*comparison here*/ t)
{
}


Node* List::FindMinNode(Node* p) const // looking through the List starting from the Node <p>
{
    Node* node=p->pNext;
    p=p->pNext;
    while(p!=Tail.pPrev)
    {
        Node* next=p->pNext;
        if((this->*m_pf)(p,next))
            node=next;
        p=p->pNext;
    }
    return node;
}

ostream& operator<<(ostream& o, const List& l)
{
    l.Print(o); // print List
    return o;
}

void List::Print(ostream& o) const // print List
{
    Node* node=Head.pNext;
    while(node!=&Tail)
    {
        node->m_Data->Print(o); // print Shape
        node=node->pNext;
    }
}


istream& operator>>(istream& i,List& l)
{
    l.Read(i);
    return i;
}

void List::Read(istream& i)
{
    Node* node=&Head; // current Node in the List into which we are reading
    int x,y,R,c,w,h; // parameters of Shape
    char type; // type of Shape (R/C)
    char str[20]; // for storage of string read from a file
    while(!i.eof()) // read while end of file is not reached
    {
        i.getline(str,_countof(str)); // read the string
        if(str[0]=='\0') // if an empty string (between nodes)
            continue;
        // Read content of Node.
        // Common part for Circle and Rect:
        sscanf_s(str,"%1c",&type); // read type of Shape (R/C)
        i.getline(str,_countof(str));
        sscanf_s(str,"%*10c %d", &c); // skip "Colour is "
        i.getline(str,_countof(str));
        sscanf_s(str,"%*4c %d", &x); // skip "x = "
        i.getline(str,_countof(str));
        sscanf_s(str,"%*4c %d", &y); // skip "y = "
        i.getline(str,_countof(str));
        if(type=='C') // if we are reading a Circle
        {
            sscanf_s(str,"%*9c %d", &R); // skip "Radius = "
            if(node->pNext!=&Tail)
            {
                if(Circle* pC=dynamic_cast<Circle*>(node->pNext->m_Data)) // if Node contains a Circle,
                    pC->ChangeData(x,y,R,static_cast<Color>(c)); // than enough to change data
                else // dynamic_cast returned 0
                {
                    delete node->pNext->m_Data;
                    node->pNext->m_Data=new Circle(x,y,R,static_cast<Color>(c));
                }
            }
            else // there is no more Nodes in the List
                AddToTail(new Circle(x,y,R,static_cast<Color>(c)));
        }
        if(type=='R') // if we are reading a Rect
        {
            sscanf_s(str,"%*8c %d", &w); // skip "Width = "
            i.getline(str,_countof(str));
            sscanf_s(str,"%*9c %d", &h); // skip "Height = "
            if(node->pNext!=&Tail)
            {
                if(Rect* pC=dynamic_cast<Rect*>(node->pNext->m_Data)) // if Node contains a Rect,
                    pC->ChangeData(x,y,w,h,static_cast<Color>(c)); // than enough to change data
                else // dynamic_cast returned 0
                {
                    delete node->pNext->m_Data;
                    node->pNext->m_Data=new Rect(x,y,w,h,static_cast<Color>(c));
                }
            }
            else // there is no more Nodes in the List
                AddToTail(new Rect(x,y,w,h,static_cast<Color>(c)));
        }
        node=node->pNext;
    }
}

List::List(const List& l)
{
    Head.pNext=&Tail;
    Tail.pPrev=&Head;
    m_size=0;
    Head.m_Data=Tail.m_Data=nullptr; // for the sake of correct call of destructors for nested Nodes

    *this=l;
}

List::List(List&& l)
{
    *this=std::move(l);
}

List& List::operator=(const List& l)
{
    if(this!=&l)
    {
        Node* node=Head.pNext;
        Node* lNode=l.Head.pNext;

        if(m_size!=0)
        {
            // Make a copy of "common part":
            while(node->pNext!=&Tail && lNode->pNext!=&l.Tail)
            {
                try
                {
                    *node->m_Data=*lNode->m_Data; // call 'operator=' for class of type '*node->m_Data'
                }
                catch(...) // assignment is impossible (objects have different types - Circle & Rect)
                {
                    delete node->m_Data;
                    node->m_Data=lNode->m_Data->Clone();
                }
                node=node->pNext;
                lNode=lNode->pNext;
            }
        }
        if(m_size<l.m_size) // if <l> has more elements, but our List is already full
        {
            while(lNode!=&l.Tail)
            {
                AddToTail(lNode->m_Data->Clone());
                lNode=lNode->pNext;
            }
        }
        else // if we reach the end of <l> than it is necessary to delete useless elements in our List
        {
            node=node->pPrev;
            while(node->pNext!=&Tail)
            {
                delete node->pNext;
                node=node->pNext;
                m_size--;
            }
        }
    }

    return *this;
}

List& List::operator=(List&& l)
{
    if(this!=&l)
    {
        if(l.m_size==0)
        {

            Head.pNext=&Tail;
            Tail.pPrev=&Head;
            m_size=0;
        }
        else
        {
            // point Head and Tail of the new List to Head and Tail of the old one
            Head.pNext=l.Head.pNext;
            Head.pNext->pPrev=&Head;
            Tail.pPrev=l.Tail.pPrev;
            Tail.pPrev->pNext=&Tail;
            m_size=l.m_size;
        }

        // deleting of old links
        l.Head.pNext=&l.Tail;
        l.Tail.pPrev=&l.Head;
        l.m_size=0; // redundantly

    }

    return *this;
}
