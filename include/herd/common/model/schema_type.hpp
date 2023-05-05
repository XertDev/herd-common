#ifndef HERD_COMMON_SCHEMA_TYPE_HPP
#define HERD_COMMON_SCHEMA_TYPE_HPP

#include <cstdint>


namespace herd::common
{
	enum class SchemaType : uint8_t
	{
		NONE,
		BINFHE
	};
}

#endif //HERD_COMMON_SCHEMA_TYPE_HPP
