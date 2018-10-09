//#include <cstdio>

// v0.1
// wrong version, memory limited exceeded!
// struct Node
// {
// 	Node* next;
// 	int data;

// 	Node(): next(NULL), data(0)
// 	{

// 	}
// }__attribute__ ((packed));

// struct Compare
//  {
//  	/* data */
//  	bool operator ()(const Node* lhs, const Node* rhs) const
//  	{
//  		return lhs->data < rhs->data;
//  	}
//  };

 // struct Deque
 // {
 // 	Node* node;
 // 	Deque* next;

 // 	Deque(): node(NULL), next(NULL)
 // 	{

 // 	}
 // }__attribute__ ((packed));

// class MinStack {
// public:
// 	MinStack();

// 	~MinStack();

//     void push(int x);

//     void pop();

//     int top();

//     int getMin();
// private:
// 	Node* m_head;
// 	Deque* m_dequeHead;
// };

// MinStack::MinStack() : m_head(NULL), m_dequeHead(NULL)
// {

// }

// MinStack::~MinStack()
// {
// 	while (m_head != NULL)
// 	{
//         pop();
// 	}
// }

// void MinStack::push(int x)
// {
// 	Node* newNode = new Node();

// 	newNode->data = x;

// 	newNode->next = m_head;
// 	m_head = newNode;

// 	if (m_dequeHead == NULL)
// 	{
// 		m_dequeHead = new Deque();
// 		m_dequeHead->node = m_head;
// 	}
// 	else
// 	{
// 		if (m_dequeHead->node->data >= x)
// 		{
// 			Deque* deq = new Deque();

// 			deq->next = m_dequeHead;
// 			deq->node = newNode;

// 			m_dequeHead = deq;
// 		}
// 	}

// }

// void MinStack::pop()
// {
// 	if (m_head == NULL)
// 	{
// 		return;
// 	}

// 	if (m_dequeHead->node == m_head)
// 	{
// 		Deque* tmp = m_dequeHead->next;

// 		delete m_dequeHead;
// 		m_dequeHead = tmp;
// 	}

// 	Node* next = m_head->next;

// 	delete m_head;
// 	m_head = next;
// }

// int MinStack::top()
// {
// 	return m_head->data;
// }

// int MinStack::getMin()
// {
// 	return m_dequeHead->node->data;
// }

// v0.2
// use STL stack
#include <stack>
#include <cstdio>

using std::stack;

class MinStack {
public:
    void push(int x);

    void pop();

    int top();

    int getMin();
private:
	//data
	stack<int> m_stack;
	//for min value
	stack<int> m_minDeque;
};

void MinStack::push(int x)
{
    m_stack.push(x);

    if (m_minDeque.empty() || x <= m_minDeque.top())
    {
    	m_minDeque.push(x);
    }
}

void MinStack::pop()
{
	if (m_stack.top() == m_minDeque.top())
	{
		m_minDeque.pop();
	}
	m_stack.pop();
}

int MinStack::top()
{
	return m_stack.top();
}

int MinStack::getMin()
{
	return m_minDeque.top();
}

int main()
{
    return 0;
}
