#pragma once

#include <string>
#include <vector>

#define LOWERCASE_SIZE  26
#define UPPERCASE_SIZE  26
#define UPPERLOWER_SIZE 52
#define ALPHANUM_SIZE	62
#define ASCII_SIZE	    128
#define UNICODE_SIZE    256


struct TrieNode{
	int m_count;
	bool m_bIsEnd;
	TrieNode() {
		m_count = 0;
		bool m_bIsEnd = false;
	}
};

class CTrie {
public:
	CTrie(){
	}
	~CTrie() {

	}

	bool add_word(const std::string& word) {
		return true;
	}

	bool find_word(const std::string& word) {

	}

	std::vector<std::string> find_prefix(const std::string &word) {

	}

private:


};