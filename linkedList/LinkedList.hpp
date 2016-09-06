/**
*	@author Deema ALShoaibi
*	@date 9/2/2016
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	/**   req #1    */
	int counter = 0;
	if( isEmpty() )
		return( 0 );
	else{
		Node<T>* temp = m_front;
		while( temp != nullptr )
		{
			counter++;
			temp = temp->getNext();
		}
		return(counter );}
	/*  End of added code of req #1 */
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;
	/**   req #2  on search method  */
	while(  !isFound && temp != nullptr)
	{
		 if( temp->getValue() == value){
			 isFound = true;
			 break;
		}
		 else
			temp  = temp->getNext();

	}

	return( isFound );
       /*  End of added code of req #2 */
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	Node<T>* temp = nullptr;

	bool isRemoved = false;
	int counter =0;
	int i=0;

	/** req #3*/
	if(!isEmpty()){
	if( size() == 1){
		m_front = nullptr;
		m_size--;
		isRemoved = true;
	}
	else{
		int i=0;
		secondintoLast = m_front;
		lastNode = secondintoLast->getNext();
		while ( i < size() -2){
		secondintoLast = secondintoLast->getNext();
		lastNode = lastNode->getNext();
		i++;
		}
		secondintoLast->getNext() = nullptr;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
	/* changes made for req #3*/
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
