#pragma once

#include <string>
#include <vector>

#define LOWERCASE_SIZE  26
#define UPPERCASE_SIZE  26
#define UPPERLOWER_SIZE 52
#define ALPHANUM_SIZE	62
#define ASCII_SIZE	    128
#define UNICODE_SIZE    256

namespace mtools {
	struct TrieNode {
		int m_count;
		bool m_bIsEnd;
		int m_size;
		char m_str;
		std::vector<TrieNode*> m_nodes;
		TrieNode(unsigned int size) {
			m_count = 0;
			m_size = size;
			m_bIsEnd = false;
			m_nodes = std::vector<TrieNode*>(size);
		}

		~TrieNode() {
			delete_trie();
		}

		void delete_trie() {
			for (unsigned int i = 0; i < m_nodes.size(); ++i) {
				if (m_nodes[i] != NULL) {
					delete m_nodes[i];
					m_nodes[i] = NULL;
				}
			}
		}
	};


	// This implementation is working for lower case alpha only.
	// Todo : Implement one that can go either ASCII, Lower, Upper, both + num etc..
	class CTrie {
	public:
		CTrie() {
			m_root = new TrieNode(LOWERCASE_SIZE);
		}
		CTrie(unsigned int size) {
			m_root = new TrieNode(size);
		}

		~CTrie() {
			delete m_root;
			m_root = NULL;
		}

		bool find_word(const std::string& word) {
			return find_word(word, m_root);
		}

		std::vector<std::string> find_prefix(const std::string &word) {

		}

		void add_word(const std::string& word) {
			add_word(word, m_root);
		}

	private:

		void add_word(const std::string& word, TrieNode* root)
		{
			if (word.size() == 0) return;
			int index = word[0] - 'a';
			
			if (index > root->m_nodes.size()) return;
			if (root->m_nodes[index] == nullptr) {
				root->m_nodes[index] = new TrieNode(root->m_size);
			}
			if (word.size() == 1) {
				root->m_nodes[index]->m_bIsEnd = true;
			}
			root->m_nodes[index]->m_count++;
			root->m_nodes[index]->m_str = word[0];
			add_word(std::string(word.begin() + 1, word.end()), root->m_nodes[index]);
		}

		bool find_word(const std::string& word, TrieNode* root) {
			if (root == nullptr || word.size() == 0) return false;
			int index = word[0] - 'a';
			if (root->m_nodes[index] != NULL) {
				if (word.size() == 1) {
					return root->m_nodes[index]->m_bIsEnd;
				}
				else {
					return find_word(std::string(word.begin() + 1, word.end()), root->m_nodes[index]);
				}
			}
			return false;
		}

		void remove_word(const std::string& word, TrieNode* root) {
			if (root == nullptr || word.size() == 0) return;

			int index = word[0] - 'a';
			root->m_nodes[index]->m_count--;
		}

	private:

		TrieNode* m_root;
	};
}