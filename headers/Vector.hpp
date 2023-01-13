#pragma once
#include <ostream>
namespace mtl {
	template <typename T>
	class Vector {
	private:
		T* arr;
		size_t _size{};
		size_t _capacity{};
		void addMemory() {
			T* tmp = arr;
			_capacity = 1.5 * _capacity + 1;
			arr = new T[_capacity];
			for (size_t i = 0; i < _size; i++) arr[i] = tmp[i];
			delete[] tmp;
		}
	public:
		Vector(size_t size = 0, T var = 0): _capacity(size + 1), _size(size) {
			arr = new T[_capacity];
			for (int i = 0; i < _size; i++)
				arr[i] = var;
		}
		~Vector() {
			delete[] arr;
		}
		Vector(Vector& other) {
			arr = new T[other._capacity];
			for (size_t i = 0; i < other._size; ++i) arr[i] = other.arr[i];
			_size = other._size;
			_capacity = other._capacity;
		}
		Vector(Vector&& other) noexcept {
			arr = other.arr;
			_size = other._size;
			_capacity = other._capacity;
			other.arr = nullptr;
			other._size = other._capacity = 0;
		}
		Vector& operator=(Vector& other) {
			if (this != &other)
			{
				delete[] arr;
				arr = new T[other._capacity];
				for (size_t i = 0; i < other._size; i++) arr[i] = other.arr[i];
				_size = other._size;
				_capacity = other._capacity;
			}
			return *this;
		}
		T& operator[](size_t index) {
			return arr[index];
		}
		const T& operator[](size_t index) const {
			return arr[index];
		}
		bool isEmpty() const {
			return _size == 0;
		}
		size_t size() const {
			return _size;
		}
		size_t capacity() const {
			return _capacity;
		}
		
		void push_back(const T& value) {
			if (_size >= _capacity) addMemory();
			arr[_size++] = value;
		}
		void remove(size_t index) {
			for (size_t i = index + 1; i < _size; i++)
			{
				arr[i - 1] = arr[i];
			}
			--_size;
		}

		T* begin() {
			return &arr[0];
		}
		const T* begin() const {
			return &arr[0];
		}
		T* end() {
			return &arr[_size];
		}
		const T* end() const {
			return &arr[_size];
		}
	};
	template <typename T>
	inline std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
		for (size_t i = 0; i < vec._size(); ++i) os << vec[i] << " ";
		return os;
	}
}
