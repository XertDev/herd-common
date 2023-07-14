#include "herd/common/native_type_mapping.hpp"


namespace herd::common
{
	unsigned int data_type_to_bit_width(herd::common::DataType type) noexcept
	{
		switch(type)
		{
			using enum herd::common::DataType;
			case DataType::BIT:
				return NativeTypeMapping<DataType::BIT>::bit_size;
			case DataType::UINT8:
				return NativeTypeMapping<DataType::UINT8>::bit_size;
			case DataType::INT8:
				return NativeTypeMapping<DataType::INT8>::bit_size;
			case DataType::UINT16:
				return NativeTypeMapping<DataType::UINT16>::bit_size;
			case DataType::INT16:
				return NativeTypeMapping<DataType::INT16>::bit_size;
			case DataType::UINT32:
				return NativeTypeMapping<DataType::UINT32>::bit_size;
			case DataType::INT32:
				return NativeTypeMapping<DataType::INT32>::bit_size;
			case DataType::UINT64:
				return NativeTypeMapping<DataType::UINT64>::bit_size;
			case DataType::INT64:
				return NativeTypeMapping<DataType::INT64>::bit_size;
		}
	}
}