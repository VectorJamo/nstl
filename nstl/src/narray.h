#pragma once

#include <assert.h>

namespace nstl {
	template<typename T, int size>
	class array
	{
	private:
		T data[size];

	public:
		array();
		
		void Fill(T value);

		inline unsigned int GetSize() const { return size; }
		T& operator[](int index);
		const T& operator[] (int index) const;

	};


	template<typename T, int size>
	array<T, size>::array()
	{
	}

	template<typename T, int size>
	void array<T, size>::Fill(T value)
	{
		for (int i = 0; i < size; i++)
			data[i] = value;
	}

	template<typename T, int size>
	T& array<T, size>::operator[](int index)
	{
		assert(index + 1 <= size, "ARRAY OUT OF BOUNDS!");
		return data[index];
	}

	template<typename T, int size>
	const T& array<T, size>::operator[](int index) const
	{
		assert(index + 1 <= size, "ARRAY OUT OF BOUNDS!");
		return data[index];
	}
}
