#pragma once

namespace mtl
{
	template <typename T>
	class List
	{
		template <typename T>
		class Node
		{
		public:
			T val;
			Node<T> *next;
			Node<T> *prev;
		};

		Node<T> *_begin;
		Node<T> *_end;
		size_t _size{};
		void quickSort(size_t left, size_t right)
		{
			size_t curSize = right - left + 1;
			int i = left;
			int j = right;
			T mid = this->operator[](left + (curSize >> 1));
			do
			{
				while (this->operator[](i) < mid) i++;
				while (this->operator[](j) > mid) j--;
				if (i <= j)
				{
					T tmp = this->operator[](i);
					this->operator[](i) = this->operator[](j);
					this->operator[](j) = tmp;
					i++;
					j--;
				}
			} while (i <= j);
			if (j > 0 && this->operator[](i) != this->operator[](j)) quickSort(0, (curSize >> 1) - 1);
			if (i < curSize && this->operator[](i) != this->operator[](j)) quickSort((curSize >> 1) + 1, size() - 1);
		}
	public:
		List() : _size(0), _begin(nullptr), _end(nullptr)
		{};
		List(const List& other)
		{
			if (other.empty())
			{
				_size = 0;
				return;
			}

			_begin = new Node<T>();
			_begin->val = other._begin->val;
			Node<T> *cur = other._begin->next;
			Node<T> *buff = _begin;
			Node<T> *prevBuff = _begin;
			while (cur != nullptr)
			{
				buff->next = new Node<T>();
				buff = buff->next;
				buff->prev = prevBuff;
				buff->val = cur->val;
				prevBuff = prevBuff->next;
				cur = cur->next;
			}
			_end = buff;
			
		};
		List(List&& other)
		{};
		~List()
		{
			//while (_begin != nullptr)
			//{
			//	Node<T> * next = _begin->next;
			//
			//	delete _begin;
			//	_begin = next;
			//}
			
		}
		List<T> operator=(const List<T>& other)
		{
			if (this != &other)
			{
				this->clear();
				Node<T>* listNode = other._begin;
				while (listNode != nullptr)
				{
					push_back(listNode->val);
					listNode = listNode->next;
				}
			}
			return *this;
		}
		T front() const
		{
			return _begin->val;
		}
		T back()
		{
			return _end->val;
		}
		bool empty() const
		{
			return size() == 0;
		}
		size_t size() const
		{
			return _size;
		}
		void clear()
		{
			while (_begin != nullptr)
			{
				Node<T>* next = _begin->next;
				delete _begin;
				_begin = next;
			}
			_end = nullptr;
			_size = 0;
		}
		void insert(int pos, T value)
		{
			Node<T>* cur = _begin;
			if (pos == 0 || _size == 0)
			{
				cur = new Node<T>();
				cur->val = value;
				cur->next = _begin;
				_begin = cur;
				_size++;
				if (_size == 1) _end = _begin; 
				return;
			}

			// if (pos > _size) then we insert after _end;
			for (int i = 1; cur != _end && i != pos; i++, cur = cur->next);
			Node<T>* newNode = new Node<T>();
			newNode->val = value;
			newNode->next = cur->next;
			if (cur->next != nullptr) cur->next->prev = newNode;
			cur->next = newNode;
			newNode->prev = cur;
			if (pos >= _size) _end = _end->next;
			_size++;
		}
		//  ¿  ”ƒ¿À»“‹ ÕŒƒ” delete <ÛÍ‡Á‡ÚÂÎ¸ Ì‡ ÌÓ‰Û>
		void erase(int pos)
		{
			Node<T>* cur = _begin;
			if (pos > _size) return;
			if (_size == 1 && pos == 0)
			{
				delete cur;
				_begin = nullptr;
				_end = nullptr;
				_size = 0;
				return;
			}
			if (_size == 2)
			{
				if (pos == 0)
				{
					delete cur;
					_end->prev = nullptr;
					_begin = _end;
					_size = 1;
				}
				if (pos == 1)
				{
					delete _end;
					cur->next = nullptr;
					_end = _begin;
					_size = 1;
				}
				return;
			}
			for (int i = 0; i != pos; i++, cur = cur->next)
			if (pos == 0)
			{
				_begin = _begin->next;
				delete _begin->prev;
				_begin->next->prev = nullptr;
				_size -= 1;
				return;
			}
			if (pos == _size - 1)
			{
				_end = _end->prev;
				delete _end->next;
				_end->next = nullptr;
				_size -= 1;
				return;
			} 
			if (pos != 0 && pos != _size - 1)
			{
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				delete cur;
				_size -= 1;
			}
		}
		void push_back(const T value)
		{
			insert(_size, value);
		}
		void push_front(const T value)
		{
			insert(0, value);
		}
		
		void pop_back()
		{
			erase(_size - 1);
		}
		void pop_front()
		{
			erase(0);
		}
		void swap(List<T>& other)
		{
			List<T> listBuff;
			listBuff = other;
			other = *this;
			*this = listBuff;
				                                   
		}
		List<T> merge(List<T>& other)
		{
			Node<T>* cur = _begin;
			List<T> listNode;
			while (cur != nullptr)
			{
				listNode.push_back(cur->val);
				cur = cur->next;
			}
			cur = other._begin;
			while (cur != nullptr)
			{
				listNode.push_back(cur->val);
				cur = cur->next;
			}
			return listNode;
		}
		void reverse()
		{
			Node<T>* cur = _begin;
			while (cur != nullptr)
			{
				std::swap(cur->next, cur->prev);
				cur = cur->prev;
			}
			std::swap(_begin, _end);
			

		}
		void unique()
		{
			if (size() < 1) return;
			T buff = _begin->val;
			for (int i = 1; i < size();)
			{
				if (buff == this->operator[](i)) erase(i);
				else
				{
					buff = this->operator[](i);
					i++;
				}
					
			}
			
		}
		void sort()
		{
			if (empty()) return;
			quickSort(0, size() - 1);
		}
		bool operator==(const List& other)
		{
			Node<T>* cur = _begin;
			Node<T>* cur1 = other._begin;
			if (this->_size != other._size) return false;
			while (cur != nullptr)
			{
				if (cur->val != cur1->val) return false;
				cur = cur->next; 
				cur1 = cur1->next;
				
			}
			return true;
		
		}
		bool operator!=(const List& other)
		{
			Node<T>* cur = _begin;
			Node<T>* cur1 = other._begin;
			if (this->_size == other._size) return false;
			while (cur != nullptr)
			{
				if (cur->val != cur1->val) return true;
				cur = cur->next;
				cur1 = cur1->next;

			}
			return false;
		}
		bool operator<(const List& other)
		{
			if (this->_size < other._size) return true;
			else return false;
		}
		bool operator<=(const List& other)
		{
			if (this->_size <= other._size) return true;
			else return false;
		}
		bool operator>(const List& other)
		{
			if (this->_size > other._size) return true;
			else return false;
		}
		bool operator>=(const List& other)
		{
			if (this->_size >= other._size) return true;
			else return false;
		}
		T& operator[](int index)
		{
			Node<T>* cur = _begin;
			while (cur->next != nullptr && index > 0)          
			{
				
				cur = cur->next;
				index--;
				
			}
			return cur->val; // if index >= size return last element
		}
	};
};