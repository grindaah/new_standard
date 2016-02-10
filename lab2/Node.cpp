#include "stdafx.h"
#include "Node.h"


Node::Node(Node* p, const Shape* s)
{
	m_Data = s->Clone();	
	ConstructNode(p); // create necessary links between Nodes
}


Node::~Node(void)
{
	RemoveNode();
	delete m_Data;
}

void Node::RemoveNode()
{
	// remove this (change links)
	if(pPrev)
		pPrev->pNext=pNext;
	if(pNext)
		pNext->pPrev=pPrev;
}


Node::Node(Node* p, const Node* node)
{
	m_Data=node->m_Data->Clone();
	ConstructNode(p); // create necessary links between Nodes
}

void Node::ConstructNode(Node* p)
{
	// insert this-Node after Node <p>
	pPrev=p;
	pNext=p->pNext;
	p->pNext=this;
	pNext->pPrev=this;
}

