#pragma once

#include <iostream>

namespace mtools {

	template <class T>
	class Singleton
	{
	public:
		static const T* instance() {
			if (m_instance == nullptr) {
				m_instance = new T();
			}
			return m_instance;
		}

		static void destroy() {
			if (m_instance != nullptr) {
				delete m_instance;
				m_instance = nullptr;
			}
		}
	protected:
		Singleton() {}
		~Singleton() { std::cout << "~Singleton" << std::endl; }
	private:
		static T* m_instance;
	};

	template<class T>
	T* Singleton<T>::m_instance = 0;

	// Dummy class to test the Singleton
	class A : public Singleton<A> {
		friend class Singleton<A>;
	public:
		static void test() {
			std::cout << "A->test Singleton test" << std::endl;
		}

	private:
		A() {}
		~A() { std::cout << "~A" << std::endl;  }
	};
}