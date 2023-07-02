#ifndef LIBHERD_COLUMN_META_HPP
#define LIBHERD_COLUMN_META_HPP

#include <string>

#include "herd/common/model/data_type.hpp"


namespace herd::common
{
	struct ColumnMeta
	{
		std::string name;
		DataType type;

		ColumnMeta(std::string name, DataType type)
		:	name(std::move(name)), type(type)
		{};
	};
}

#endif //LIBHERD_COLUMN_META_HPP
