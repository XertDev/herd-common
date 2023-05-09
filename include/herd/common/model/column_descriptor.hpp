#ifndef HERD_COMMON_COLUMN_DESCRIPTOR_HPP
#define HERD_COMMON_COLUMN_DESCRIPTOR_HPP

#include <map>
#include <string>

#include "herd/common/model/data_type.hpp"


namespace herd::common
{
	struct ColumnDescriptor {
		ColumnDescriptor(uint8_t col_index, herd::common::DataType col_type)
		:	index(col_index), type(col_type){};

		uint8_t index;
		DataType type;
	};

	using column_map_type = std::map<std::string, ColumnDescriptor, std::less<>>;
}

#endif //HERD_COMMON_COLUMN_DESCRIPTOR_HPP
