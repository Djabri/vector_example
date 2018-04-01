#include <iostream>
#include <cassert>

template <typename T>
class vector_t
{
private:
	T * elements_;
	std::size_t size_;
	std::size_t capacity_;
public:
	vector_t();
	vector_t(vector_t const & other);
	vector_t & operator =(vector_t const & other);
	~vector_t();

	T at(std::size_t index);
	T & at(std::size_t index) const;
	std::size_t size() const;
	std::size_t capacity() const;

	void push_back(int value);
	void pop_back();
	
	int & operator [](std::size_t index);
	int operator [](std::size_t index) const;

	bool operator ==(vector_t const & other) const;
};

template <typename T>
vector_t<T>::vector_t() : elements_(nullptr), size_(0), capacity_(0)
{
}

template <typename T>
vector_t<T>::vector_t(vector_t const & other)
{
    	elements_ = new T [other.capacity_];
    	for (std::size_t i = 0; i < other.size_; i++)
    	{
        	elements_[i] = other.elements_[i];
    	}
    	capacity_ = other.capacity_;
	size_ = other.size_;
}

template <typename T>
vector_t<T> & vector_t<T>::operator =(vector_t const & other)
{
	if (this != &other)
	{
		if(elements_ != nullptr)
			delete[]elements_;
		elements_ = new T [other.capacity_];

		for (size_t i = 0; i < other.capacity_; i++)
		{
			elements_[i] = other.elements_[i];
		}
		capacity_ = other.capacity_;
		size_ = other.size_;
	}
		return *this;
}

template <typename T>
bool vector_t<T>::operator ==(vector_t const & other) const
{
	if (size_ == other.size_)
	{
		for (size_t i = 0; i < other.size_; i++)
		{
			if (elements_[i] != other.elements_[i])
			{
				return false;
				break;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
T vector_t<T>::at(std::size_t index)
{
	if (index >= size_)
	{
		throw "Error!\n Array going beyond the bounds of the array\n";
	}
	
	return elements_[index];
}

template<typename T>
T & vector_t<T>::at(std::size_t index) const
{
	if (index >= size_)
	{
		throw "Error!\n going beyond the bounds of the array";
	}
	
	return elements_[index];
}

template <typename T>
vector_t<T>::~vector_t()
{
	if(elements_ != nullptr)
	{
		delete[]elements_;
	}
}

template <typename T>
std::size_t vector_t<T>::size() const
{
    return size_;
}

template <typenmae T>
std::size_t vector_t<T>::capacity() const
{
    return capacity_;
}

template <typename T>
void vector_t<T>::push_back(int value)
{
	if (capacity_)
	{
		if ( size_ == capacity_)
		{	
			capacity_ *= 2;
			T *temp_elements = new T [capacity_];
			for (size_t i = 0; i < size_; i++)
			{
				temp_elements[i] = elements_[i];
			}

			delete[]elements_;
			
			elements_ = temp_elements;
		}
	}
	else
	{
		capacity_ = 1;
		elements_ = new int [capacity_];
	}
	
	elements_[size_++] = value;
}

template <typename T>
void vector_t<T>::pop_back()
{
	if (size_)
	{
		size_--;
		if (size_ <= ( capacity_ / 4 ))
		{
			capacity_ = capacity_ / 2;
			T * temp_elements = new T [capacity_];
			for (size_t i = 0; i < size_; i++)
			{
				temp_elements[i] = elements_[i];
			}
			
			delete[]elements_;

			elements_ = temp_elements;
		}
	}else
	{
		std::cout << "Error!\n Vector is empty\n";
	}
}

template <typename T>
T & vector_t<T>::operator [](std::size_t index)
{
	return elements_[index];
}

template <typename T>
T vector_t<T>::operator [](std::size_t index) const
{
	return elements_[index];
}

template <typename T>
bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs)
{
	return !(lhs == rhs);
}
