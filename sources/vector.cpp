#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t() : elements_(nullptr), size_(0), capacity_(0)
{
}

vector_t::vector_t(vector_t const & other)
{
	capacity_ = other.capacity_;
	size_ = other.size_;
	
	elements_ = new int [capacity_];
	for (size_t i = 0; i < capacity_; i++)
	{
		elements_[i] = other.elements_[i];
	}
}

vector_t & vector_t::operator =(vector_t const & other)
{
	delete[]elements_;
	elements_ = new int [other.capacity_];
	
	for (size_t i = 0; i < other.capacity_; i++)
	{
		elememnts_[i] = other.elements_[i];
	}
	capacity_ = other.capacity_;
	size_ = other.size_;
	
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	for (size_t i = 0; i < other.capacity_; i++)
	{
		if (elements_[i] == other.elements_[i])
		{
			return true;
		}
	}
	
	return false;
}

vector_t::~vector_t()
{
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value)
{
	
}

void vector_t::pop_back()
{
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[0];
}

int vector_t::operator [](std::size_t index) const
{
	return 0;
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	return true;
}
