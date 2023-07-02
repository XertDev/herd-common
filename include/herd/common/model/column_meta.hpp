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

		ColumnMeta(std::string column_name, DataType column_type)
		:	name(std::move(column_name)), type(column_type)
		{};
	};
}

#endif //LIBHERD_COLUMN_META_HPP
