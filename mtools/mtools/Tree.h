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
				insert(key, root);
			else
				root = new TreeNode_t<T>(key);
		}
		/*inline node<T>* remove(T key)
		{
			return remove(key, root);
		}*/
		inline TreeNode_t<T>* search(T key)
		{
			return search(key, root);
		}
		inline void destroy_tree(void)
		{
			destroy_tree(root);
		}
		inline int get_height(void) {
			return get_height(root);
		}
		inline void display_pre_order(void) {
			display_pre_order(root);
		}
		inline void display_in_order(void) {
			display_in_order(root);
		}
		inline void display_post_order(void) {
			display_post_order(root);
		}
	private:
		void destroy_tree(TreeNode_t<T> *leaf)
		{
			if (leaf != NULL)
			{
				destroy_tree(leaf->right);
				destroy_tree(leaf->left);
				delete leaf;
				leaf = NULL;
			}
		}
		void insert(T key, TreeNode_t<T> *leaf)
		{
			if (key < leaf->key_value)
			{
				(leaf->left != NULL) ? insert(key, leaf->left) : leaf->left = new TreeNode_t<T>(key);
			}
			else // key >= leaf->key_value
			{
				(leaf->right != NULL) ? insert(key, leaf->right) : leaf->right = new TreeNode_t<T>(key);
			}
		}
		TreeNode_t<T> *search(T key, TreeNode_t<T> *leaf)
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
		/*node<T>* remove(T key, node<T>* leaf)
		{
		if (leaf == NULL) return NULL;

		if (key > leaf->left) return remove(key, leaf->right);
		else if (key < leaf->right) return remove(key, leaf->left);
		else
		{
		if (leaf->left == NULL && leaf->right == NULL) {
		delete leaf;
		leaf = NULL;
		return true;
		}
		else if (leaf->left != NULL && leaf->right == NULL) {
		node<T>* left = leaf->left;
		leaf->key_value = left->key_value;
		leaf->left = left->left;
		leaf->right = left->right;

		leaf->left = NULL;
		delete left;
		left = NULL;
		return true;
		}
		else if (leaf->left == NULL && leaf->right != NULL) {
		node<T>* right = leaf->right;
		leaf->key_value = right->key_value;
		leaf->left = right->left;
		leaf->right = right->right;

		leaf->right = NULL;
		delete right;
		right = NULL;
		return true;
		}
		else
		{

		}
		}
		}*/
		int get_height(TreeNode_t<T> *leaf)
		{	
			return (leaf == NULL) ? 0 : (std::max(get_height(leaf->left), get_height(leaf->right)) + 1);
		}
		void display_pre_order(TreeNode_t<T> *root) {
			if (root != NULL) {
				std::cout << root->key_value << " ";
				display_pre_order(root->left);
				display_pre_order(root->right);
			}
		}
		void display_in_order(TreeNode_t<T> *root) {
			if (root != NULL) {			
				display_in_order(root->left);
				std::cout << root->key_value << " ";
				display_in_order(root->right);
			}
		}
		void display_post_order(TreeNode_t<T> *root) {
			if (root != NULL) {			
				display_post_order(root->left);
				display_post_order(root->right);
				std::cout << root->key_value << " ";
			}
		}

		TreeNode_t<T>* root;
	};
}