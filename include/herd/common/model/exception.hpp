#ifndef HERD_COMMON_EXCEPTION_HPP
#define HERD_COMMON_EXCEPTION_HPP

#include <stdexcept>

namespace herd::common
{
	struct IOError: public std::runtime_error
	{
		using std::runtime_error::runtime_error;
	};

	struct FileNotExistError: public IOError
	{
		using IOError::IOError;
	};

	struct IOReadError: public IOError
	{
		using IOError::IOError;
	};

	struct IOWriteError: public IOError
	{
		using IOError::IOError;
	};
}

#endif //HERD_COMMON_EXCEPTION_HPP
