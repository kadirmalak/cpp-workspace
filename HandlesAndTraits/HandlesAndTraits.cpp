// HandlesAndTraits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <crtdbg.h>

#define ASSERT _ASSERTE

#if _DEBUG
#define VERIFY _ASSERT
#else
#define VERIFY(exp) (exp)
#endif // _DEBUG

namespace KadirMalak
{
	template <typename Traits>
	class unique_handle
	{
		typedef typename Traits::pointer pointer;

		pointer m_value;

		void close() throw()
		{
			if (*this) {
				Traits::close(m_value);
			}
		}

	public:
		explicit unique_handle(pointer value = Traits::invalid()) throw() : m_value{ value }
		{

		}

		~unique_handle()
		{
			close();
		}

		explicit operator bool() const throw()
		{
			return m_value != Traits::invalid();
		}

		auto get() const throw() -> pointer
		{
			return m_value;
		}
	};

	struct null_handle_traits
	{
		typedef HANDLE pointer;

		static pointer invalid() throw() 
		{
			return nullptr;
		}

		static void close(pointer value) throw()
		{
			VERIFY(CloseHandle(value));
		}
	};

	typedef unique_handle<null_handle_traits> null_handle;
}

using namespace std;
using namespace KadirMalak;

int main()
{
	//auto raw = HANDLE{ nullptr };
	//auto h = null_handle{raw};

	auto event = null_handle {
		CreateEvent(nullptr, true, false, nullptr)
	};

	if (event) {
		VERIFY(SetEvent(event.get()));
	}

	//bool b = h; // does not compile!
	bool b = static_cast<bool>(event);

    return 0;
}

