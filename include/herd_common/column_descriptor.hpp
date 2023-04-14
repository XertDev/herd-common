#ifndef HERDSMAN_COLUMNS_HPP
#define HERDSMAN_COLUMNS_HPP

#include <map>
#include <string>

#include "herd_common/data_type.hpp"


namespace herd::common
{
	struct ColumnDescriptor
	{
		ColumnDescriptor(uint8_t col_index, herd::common::DataType col_type)
				: index(col_index), type(col_type)
		{};

		uint8_t index;
		herd::common::DataType type;
	};

	using column_map_type = std::map<std::string, ColumnDescriptor, std::less<>>;
}

#endif //HERDSMAN_COLUMNS_HPP
