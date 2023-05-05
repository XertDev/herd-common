#ifndef HERD_COMMON_COLUMN_TYPE_HPP
#define HERD_COMMON_COLUMN_TYPE_HPP

#include <cstdint>


namespace herd::common
{
	enum class DataType: uint8_t
	{
		BIT,

		UINT8,
		UINT16,
		UINT32,
		UINT64,

		INT8,
		INT16,
		INT32,
		INT64
	};
}

#endif //HERD_COMMON_COLUMN_TYPE_HPP
