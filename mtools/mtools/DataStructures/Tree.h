#pragma once

namespace mtools
{
	template <class T>
	struct TreeNode_t
	{
		T key_value;
		TreeNode_t *left;
		TreeNode_t *right;

		TreeNode_t()
		{
			key_value = 0;
			left = NULL;
			right = NULL;
		}

		TreeNode_t(T value)
		{
			key_value = value;
			left = NULL;
			right = NULL;
		}

		TreeNode_t operator=(const TreeNode_t& other)
		{
			key_value = other.key_value;
			left = other.left;
			right = other.right;
		}

		~TreeNode_t()
		{ 
			// do nothing - memory management is handled by the CTree. 
		}
	};

	template <class T>
	class CTree
	{
	
	public:
		CTree() {
			root = NULL;
		}
		~CTree() {
			destroy_tree();
		}
		void insert(const T& key) {
			if (root != NULL)
				insert(key, root);
			else
				root = new TreeNode_t<T>(key);
		}
		inline TreeNode_t<T>* remove(T key) {
			return remove(key, root);
		}
		TreeNode_t<T>* search(const T& key) const {
			return search(key, root);
		}
		void destroy_tree() {
			destroy_tree(root);
		}
		void display_pre_order() const {
			display_pre_order(root);
		}
		void display_in_order() const  {
			display_in_order(root);
		}
		void display_post_order() const  {
			display_post_order(root);
		}
		int get_height() const  {
			return get_height(root);
		}
	
	private:
		void destroy_tree(TreeNode_t<T>* leaf) {
			if (leaf != NULL) {
				destroy_tree(leaf->right);
				destroy_tree(leaf->left);
				delete leaf;
				leaf = NULL;
			}
		}
		void insert(const T& key, TreeNode_t<T>* leaf) {
			if (key < leaf->key_value) {
				(leaf->left != NULL) ? insert(key, leaf->left) : leaf->left = new TreeNode_t<T>(key);
			}
			else {
				(leaf->right != NULL) ? insert(key, leaf->right) : leaf->right = new TreeNode_t<T>(key);
			}
		}
		TreeNode_t<T>* min_value_recursive(TreeNode_t<T>* leaf) {
			if (leaf->left == NULL) {
				return leaf;
			}
			else {
				return min_value(leaf->left);
			}
		}
		TreeNode_t<T>* min_value(TreeNode_t<T>* leaf) {
			TreeNode_t<T>* min_leaf = leaf;
			while (min_leaf != NULL && min_leaf->left != NULL) {
				min_leaf = min_leaf->left;
			}
			return min_leaf;
		}
		TreeNode_t<T>* search(const T& key, TreeNode_t<T> *leaf)
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
		TreeNode_t<T>* remove(const T& key, TreeNode_t<T>* leaf)
		{
			if (leaf == NULL) return leaf;

			if (key < leaf->key_value) 
				leaf->left = remove(key, leaf->left);
			else if (key > leaf->key_value)
				leaf->right = remove(key, leaf->right);
			else
			{
				//case one
				if (leaf->left == NULL) {
					TreeNode_t<T>* t = leaf->right;
					delete leaf;
					leaf = NULL;
					return t;
				}//case two
				else if (leaf->right == NULL) {
					TreeNode_t<T>* t = leaf->left;
					delete leaf;
					leaf = NULL;
					return t;
				}//case two
				else {
					TreeNode_t<T>* min = min_value(leaf->right);
					leaf->key_value = min->key_value;
					leaf->right = remove(min->key_value, leaf->right);
				}
			}

			return leaf;
		}
		TreeNode_t<T>* remove_branch(const T& key, TreeNode_t<T>* leaf) {
			if (leaf == NULL) {
				return NULL;
			}

			if (leaf->left == NULL && leaf->right == NULL) {
				delete leaf;
				return NULL;
			}
			root->left = remove(leaf->left);
			root->right = remove(leaf->right);
			return leaf;
		}
		void display_pre_order(const TreeNode_t<T> *root) const {
			if (root != NULL) {
				std::cout << root->key_value << " ";
				display_pre_order(root->left);
				display_pre_order(root->right);
			}
		}
		void display_in_order(const TreeNode_t<T> *root) const {
			if (root != NULL) {			
				display_in_order(root->left);
				std::cout << root->key_value << " ";
				display_in_order(root->right);
			}
		}
		void display_post_order(const TreeNode_t<T> *root) const {
			if (root != NULL) {			
				display_post_order(root->left);
				display_post_order(root->right);
				std::cout << root->key_value << " ";
			}
		}
		int get_height(const TreeNode_t<T>* leaf) const {
			return (leaf == NULL) ? 0 : (std::max(get_height(leaf->left), get_height(leaf->right)) + 1);
		}
		TreeNode_t<T>* root;
	};
}