#pragma once
#include <vector>
namespace mtl
{
	template <typename T>
	class Set
	{
		uint64_t _size = 0;
	public:
		template <typename T>
		class TreeNode
		{
		public:
			T key;
			TreeNode<T>* right;
			TreeNode<T>* left;
			uint8_t height;
			TreeNode(T key = T(), uint8_t height = 0, TreeNode<T>* right = nullptr, TreeNode<T>* left = nullptr) :
				key(key), height(height), right(right), left(left)
			{};

		};
		TreeNode<T>* root;
		Set(TreeNode<T>* root = nullptr) : root(root)
		{};
		~Set()
		{
			if (this->root != nullptr)
			{
				this->root->left = nullptr;
				this->root->right = nullptr;
				this->root->key = 0;
				delete this->root;

			}
		}
		Set(const Set<T>& other)
		{
			root = nullptr;
			_size = 0;
			auto vec = rootInvec(other);
			for (int i = 0; i < vec.size(); i++)
			{
				insert(vec[i]);
			}
		}
		Set<T> operator=(const Set<T>& other)
		{
			if (this != &other)
			{
				TreeNode<T>* NodeSet = root;
				NodeSet = other.root;
				if (other.root != nullptr)
				{
					for (int i = 0; i < rootInvec(other).size(); i++)
					{
						insert(rootInvec(other)[i]);
					}
				}
			}

			return *this;
		}
		std::vector<T> rootInvec(const Set<T>& other)
		{
			std::vector<T> vec;
			getInorder(other.root, vec);
			return vec;
		}
		unsigned char height(TreeNode<T>* root)
		{
			return root ? root->height : 0;
		}
		int bfactor(TreeNode<T>* root)
		{
			return height(root->right) - height(root->left);
		}
		void fixheight(TreeNode<T>* root)
		{
			uint8_t hl = height(root->left);
			uint8_t hr = height(root->right);
			root->height = (hl > hr ? hl : hr) + 1;
		}
		TreeNode<T>* rotateright(TreeNode<T>* root)
		{
			TreeNode<T>* q = root->left;
			root->left = q->right;
			q->right = root;
			fixheight(root);
			fixheight(q);
			return q;
		}
		TreeNode<T>* rotateleft(TreeNode<T>* root)
		{
			TreeNode<T>* p = root->right;
			root->right = p->left;
			p->left = root;
			fixheight(root);
			fixheight(p);
			return p;
		}
		TreeNode<T>* balance(TreeNode<T>* root)
		{
			fixheight(root);
			if (bfactor(root) == 2)
			{
				if (bfactor(root->right) < 0)
					root->right = rotateright(root->right);
				return rotateleft(root);
			}
			if (bfactor(root) == -2)
			{
				if (bfactor(root->left) > 0)
					root->left = rotateleft(root->left);
				return rotateright(root);
			}
			return root;
		}
		TreeNode<T>* findmin(TreeNode<T>* root)
		{
			return root->left ? findmin(root->left) : root;
		}
		TreeNode<T>* removemin(TreeNode<T>* root)
		{
			if (root->left == 0)
				return root->right;
			root->left = removemin(root->left);
			return balance(root);
		}
		TreeNode<T>* remove(TreeNode<T>* root, int val)
		{
			if (!root) return 0;
			if (val < root->key)
				root->left = remove(root->left, val);
			else if (val > root->key)
				root->right = remove(root->right, val);
			else
			{
				TreeNode<T>* q = root->left;
				TreeNode<T>* r = root->right;
				delete root;
				if (!r) return q;
				TreeNode<T>* min = findmin(r);
				min->right = removemin(r);
				min->left = q;
				return balance(min);
			}
			return balance(root);
		}
		void Generalinsert(TreeNode<T>* root, T val)
		{
			if (root == nullptr)
			{
				this->root = new TreeNode<T>();
				this->root->key = val;
				return;
			}
			if (root != nullptr)
			{
				if (val > root->key && root->right != nullptr)
				{
					Generalinsert(root->right, val);
					return;
				}
				if (val < root->key && root->left != nullptr)
				{
					Generalinsert(root->left, val);
					return;
				}
				if (val < root->key)
				{
					root->left = new TreeNode<T>();
					root->left->key = val;
					balance(root);
					return;
				}
				if (val > root->key)
				{
					root->right = new TreeNode<T>();
					root->right->key = val;
					balance(root);
					return;
				}
				if (val == root->key) return;

			}

		}
		void insert(T val)
		{
			Generalinsert(root, val);
			_size++;
		}
		bool empty()
		{
			return !_size;
		}
		uint64_t size()
		{
			return _size;
		}
		void clear()
		{
			if (root != nullptr)
			{
				clearInorder(root);
				root = nullptr;
				_size = 0;
			}

		}
		void erase(T val)
		{
			if (_size)
			{
				remove(root, val);
				_size--;
			}
		}

		void swap(Set<T>& other)
		{
			TreeNode<T>* buff = this->root;
			this->root = other.root;
			other.root = buff;
			uint64_t buffs = this->_size;
			this->_size = other._size;
			other._size = buffs;


		}
		void merge(Set<T>& other)
		{
			auto vec = rootInvec(other);
			for (int i = 0; i < vec.size(); i++)
			{
				insert(vec[i]);
			}

		}
		bool find(T k)
		{
			if (generalFind(root, k)) return true;
			else return false;
			return generalFind(root, k) ? true : false;
		}
		bool generalFind(TreeNode<T>* root, T val)
		{
			if (!root) return false;
			if (root->key == val) return true;
			bool a = generalFind(root->left, val);
			if (!a) a = generalFind(root->right, val);
			return a;
		}
		bool operator == (const Set<T>& other)
		{
			balance(root);
			balance(other->root);
			if (rootInvec() = other.rootInvec()) return true;
			else return false;
		}
		bool operator != (const Set<T>& other)
		{
			balance(root);
			balance(other->root);
			if (rootInvec() = other.rootInvec()) return false;
			else return true;
		}
		bool operator < (const Set<T>& other)
		{
			balance(root);
			balance(other->root);
			if (rootInvec().size() < other.rootInvec().size()) return true;
			else return false;
		}
		bool operator <= (const Set<T>& other)
		{
			balance(root);
			balance(other->root);
			if (rootInvec().size() <= other.rootInvec().size()) return true;
			else return false;
		}
		bool operator > (const Set<T>& other)
		{
			balance(root);
			balance(other->root);
			if (rootInvec().size() > other.rootInvec().size()) return true;
			else return false;
		}
		bool operator >= (const Set<T>& other)
		{
			balance(root);
			balance(other->root);
			if (rootInvec().size() >= other.rootInvec().size()) return true;
			else return false;
		}
		void clearInorder(TreeNode<T>* root)
		{
			if (root != nullptr)
			{
				clearInorder(root->left);
				clearInorder(root->right);
				root->left = nullptr;
				root->right = nullptr;
				delete root;
			}
		}
	private:
		void getInorder(TreeNode<T>* root, std::vector<T>& vec = {})
		{
			if (root != nullptr)
			{
				getInorder(root->left, vec);
				vec.push_back(root->key);
				getInorder(root->right, vec);
			}
		}

	};
}