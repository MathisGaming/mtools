#pragma once

namespace mtools
{
	template <class T>
	struct node
	{
		T key_value;
		node *left;
		node *right;

		node()
		{
			key_value = 0;
			left = NULL;
			right = NULL;
		}

		node(T value)
		{
			key_value = value;
			left = NULL;
			right = NULL;
		}
	};

	template <class T>
	class CTree
	{
	public:
		CTree(void)
		{
			root = NULL;
		}
		~CTree(void)
		{
			destroy_tree();
		}
		void insert(T key)
		{
			if (root != NULL)
			{
				insert(key, root);
			}
			else
			{
				root = new node<T>();
				root->key_value = key;
				root->left = NULL;
				root->right = NULL;
			}
		}
		inline node<T>* search(T key)
		{
			return search(key, root);
		}
		inline void destroy_tree(void)
		{
			destroy_tree(root);
		}

	private:
		void destroy_tree(node<T> *leaf)
		{
			if (leaf != NULL)
			{
				destroy_tree(leaf->right);
				destroy_tree(leaf->left);
				delete leaf;
			}
		}
		void insert(T key, node<T> *leaf)
		{
			if (key < leaf->key_value)
			{
				if (leaf->left != NULL)
				{
					insert(key, leaf->left);
				}
				else
				{
					leaf->left = new node<T>();
					leaf->left->key_value = key;
					leaf->left->left = NULL;
					leaf->left->right = NULL;
				}
			}
			else // key >= leaf->key_value
			{
				if (leaf->right != NULL)
				{
					insert(key, leaf->right);
				}
				else
				{
					leaf->right = new node<T>();
					leaf->right->key_value = key;
					leaf->right->left = NULL;
					leaf->right->right = NULL;
				}
			}
		}
		node<T> *search(T key, node<T> *leaf)
		{
			if (leaf != NULL)
			{
				if (leaf->key_value == key)
				{
					return leaf;
				}
				if (key < leaf->key_value)
				{
					return search(key, leaf->left);
				}
				else
				{
					return search(key, leaf->right);
				}
			}
			return NULL;
		}

		node<T>* root;
	};
}