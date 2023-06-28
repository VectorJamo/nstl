#pragma once

namespace nstl {
	template<typename T>
	class vector
	{
	private:
		T* datas;
		unsigned int size, reserved_size;

	public:
		vector();
		vector(unsigned int reserved_size);
		vector(const vector& other);
		~vector();

		void push_back(T data);
		void reserve(int size);

		T operator[](int index);

		inline unsigned int GetSize() { return size; }
		inline unsigned int GetReservedSize() { return reserved_size; }
	};

	template<typename T>
	vector<T>::vector()
		:datas(nullptr), size(0), reserved_size(5)
	{
		datas = new T[reserved_size];
	}

	template<typename T>
	vector<T>::vector(unsigned int reserved_size)
		:datas(nullptr), size(0), reserved_size(reserved_size)
	{
		datas = new T[reserved_size];
	}

	template<typename T>
	vector<T>::vector(const vector& other)
		:size(other.size), reserved_size(other.reserved_size)
	{
		datas = new T[reserved_size];
		memcpy(datas, other.datas, sizeof(T) * other.size);
	}

	template<typename T>
	vector<T>::~vector()
	{
		delete[] datas;
	}

	template<typename T>
	void vector<T>::push_back(T data)
	{
		size++;

		if (size > reserved_size)
		{
			reserved_size += 3;
			T* temp = new T[reserved_size];
			memcpy(temp, datas, sizeof(T) * size - 1);
			temp[size - 1] = data;

			delete[] datas;
			datas = temp;
		}
		else {
			datas[size - 1] = data;
		}
	}
	template<typename T>
	void vector<T>::reserve(int size)
	{
		if (this->size != 0 && size > this->size)
		{
			reserved_size = size;
			T* temp = new T[reserved_size];
			memcpy(temp, datas, sizeof(T) * this->size);

			delete[] datas;
			datas = temp;
		}else if(this->size == 0){
			
			reserved_size = size;
			delete[] datas;
			datas = new T[reserved_size];
		}
	}

	template<typename T>
	T vector<T>::operator[](int index)
	{
		return datas[index];
	}
}
