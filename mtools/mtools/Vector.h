#pragma once

#include <new>
// http://upcoder.com/3/roll-your-own-vector

namespace mtools
{
	class CVector
	{
	public:
		typedef typename std::size_t size_type;
	private:
		size_type _size;
		size_type _capacity;
	public:
		CVector();
		~CVector();
	};
}