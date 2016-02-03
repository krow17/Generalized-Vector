/*Gen_vec.h
Kyle Rowland
Header file for a templated vector data structure
*/

#include <iostream>

using namespace std;
// instantiation of objects, variables, and functions
template <class T> class Gen_vec
{
	private:
			//member variables
			int size, capacity;
			T *ptr;
	public:
		//member functions 
		Gen_vec();
		~Gen_vec();
		Gen_vec(const Gen_vec<T>& vec);
		Gen_vec& operator=(const Gen_vec<T>& vec);
		int get_size() const;
		int get_capacity() const;
		T& operator[](int i) const;
		T& operator[](int i);
		bool is_empty() const;
		T& elem_at_rank(int r) const;
		void insert_at_rank(int r, const T& elem);
		void replace_at_rank(int r, const T& elem);
		void remove_at_rank(int r);
		void find_max_index(const Gen_vec<T>& v);
		void resize_array();
};

template <class T>
ostream& operator<<(ostream& out, const Gen_vec<T>& vec);

//template <class T>
//void sort_max(Gen_vec<T>& vec);

//--------------------------------------------------------------------
//definitions of objects, variables, and functions

template<class T>Gen_vec<T>::Gen_vec(): size(0), capacity(10), ptr(new T[capacity]) {}

template<class T>Gen_vec<T>::~Gen_vec() // destructor
{
	delete[] ptr;
}
template<class T> int Gen_vec<T>::get_size() const // returns number of elements in vector
{
	return size;
}
template<class T> int Gen_vec<T>::get_capacity() const // returns available space in vector
{
	return capacity;
}
template<class T> bool Gen_vec<T>::is_empty() const // checks to see if vector is empty
{
	return size == 0;
}
template<class T> Gen_vec<T>::Gen_vec(const Gen_vec<T>& vec) // copy constructor
{
	size = vec.get_size();
	capacity = vec.get_capacity();
	ptr = new T[capacity];
	for (int i = 0; i <= vec.get_capacity(); i++)
	{
		ptr[i] = vec[i];
	}
}

template<class T> void Gen_vec<T>::resize_array() // if size exceeds capacity, double the capacity
{
	int newcap = capacity * 2;
	T *temp = new T[newcap];
	
	for (int i = 0; i <= capacity; i++)
		temp[i] = ptr[i];
	
	delete[] ptr;
	ptr = temp;
}

template<class T> Gen_vec<T>& Gen_vec<T>::operator=(const Gen_vec<T>& vec) // overloaded "=" operator 
{ 
	if(this != &vec) {
		this->Gen_vec<T>::~Gen_vec();
		new(this) Gen_vec<T>(vec);
	}
	return *this;
}
template<class T> T& Gen_vec<T>::operator[](int i) const // overloaded "[]" operator
{
	return ptr[i];
}
template<class T> T& Gen_vec<T>::operator[](int i) // overloaded "[]" operator
{
	return ptr[i];
}
template<class T> T& Gen_vec<T>::elem_at_rank(int r) const {return ptr[r];} // return the value of the element at the given rank
template<class T> void Gen_vec<T>::insert_at_rank(int r, const T& elem) // add element to array at given rank
{
	if (r>capacity)
		return;
	else size++;
	if (size>capacity)
		resize_array();
	int i = size - 2;
	while(i >= r)
	{
		ptr[i+1] = ptr[i];
		i--;
	}
	ptr[i+1] = elem;
}

template<class T> void Gen_vec<T>::replace_at_rank(int r, const T& elem) // remove current element and replace it with a new one
{
	for (int j = r+1; j < size; j++)
		ptr[j-1] = ptr[j];
	size--;
	
	if (r>capacity)
		return;
	else size++;
	if (size>capacity)
		resize_array();
	int i = size - 2;
	while(i >= r)
	{
		ptr[i+1] = ptr[i];
		i--;
	}
	ptr[i+1] = elem;
}
template<class T> void Gen_vec<T>::remove_at_rank(int r) // remove element from array
{
	for (int j = r+1; j < size; j++)
		ptr[j-1] = ptr[j];
	size--;
}


template<class T> void Gen_vec<T>::find_max_index(const Gen_vec<T>& v) // return the element found at the highest rank
{
	for(int p=1;p<=size-1;p++) // Loop for Pass
	{

		for(int j=1;j<=size-1;j++)
		{
			if(ptr[j]>ptr[j+1])
			{
				T temp=ptr[j]; // Interchange Values
				ptr[j]=ptr[j+1];
				ptr[j+1]=temp;
			}
		}

	}

	std::cout<<"Max element in array is: "<<ptr[capacity - 1];
}

template<class T> ostream& operator<<(ostream& out, const Gen_vec<T>& vec) // overloaded output operators
{
	return out;
}
