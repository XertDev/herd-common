#ifndef HERD_COMMON_DAG_HPP
#define HERD_COMMON_DAG_HPP

#include <map>
#include <type_traits>
#include <vector>


namespace herd::common
{
	template<typename T>
	class DAG
	{
	public:
		using node_id_t = std::size_t;
		using value_type = std::remove_cvref_t<T>;

		class Node
		{
			using graph_type = DAG;

			const value_type& value() const noexcept;
			value_type& value() noexcept;

			Node& operator=(value_type);

		private:
			graph_type& graph_;
			std::size_t index_ = 0;
		};

		template<bool is_const>
		class NodeIterator
		{
		public:
			using graph_type = std::conditional_t<is_const, const DAG*, DAG*>;

			using self_type = NodeIterator<is_const>;
			using iterator_category = std::random_access_iterator_tag;
			using difference_type = std::ptrdiff_t;
			using value_type = std::conditional_t<is_const, const DAG::value_type, DAG::value_type>;
			using pointer = value_type*;
			using reference = value_type&;

			NodeIterator();

			operator NodeIterator<true>() const noexcept
				requires(!is_const);

			[[nodiscard]] reference operator*() const noexcept;

			[[nodiscard]] bool operator==(const self_type& other) const noexcept;
			[[nodiscard]] auto operator<=>(const self_type& other) const noexcept;

			self_type& operator++() noexcept;
			self_type& operator--() noexcept;

			self_type operator++(int) noexcept;
			self_type operator--(int) noexcept;

			self_type& operator+=(std::size_t shift) noexcept;
			self_type& operator-=(std::size_t shift) noexcept;

			[[nodiscard]] self_type operator+(std::size_t shift) const noexcept;
			[[nodiscard]] self_type operator-(std::size_t shift) const noexcept;

			[[nodiscard]] difference_type operator-(const self_type& rhs) const noexcept;

		private:
			graph_type graph_;
			std::size_t index_ = 0;

			NodeIterator(graph_type graph, std::size_t index);

			friend class DAG<T>;
		};

		using const_iterator = NodeIterator<true>;
		using iterator = NodeIterator<false>;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		template<typename V>
		iterator emplace(V&& value, const const_iterator& parent)
			requires std::is_same_v<std::remove_cvref_t<V>, T>;

		template<typename V>
		iterator emplace(V&& value)
			requires std::is_same_v<std::remove_cvref_t<V>, T>;

		void add_edge(const const_iterator& from, const const_iterator& to);

		[[nodiscard]] iterator begin() noexcept;
		[[nodiscard]] const_iterator begin() const noexcept;

		[[nodiscard]] iterator end() noexcept;
		[[nodiscard]] const_iterator end() const noexcept;

		[[nodiscard]] reverse_iterator rbegin() noexcept;
		[[nodiscard]] const_reverse_iterator rbegin() const noexcept;

		[[nodiscard]] reverse_iterator rend() noexcept;
		[[nodiscard]] const_reverse_iterator rend() const noexcept;

		[[nodiscard]] const_iterator cbegin() const noexcept;
		[[nodiscard]] const_iterator cend() const noexcept;
		[[nodiscard]] const_reverse_iterator crbegin() const noexcept;
		[[nodiscard]] const_reverse_iterator crend() const noexcept;

	private:
		std::vector<T> values_;
		std::multimap<node_id_t, node_id_t> edges_;
	};

	// Implementation

	template<typename T>
	const typename DAG<T>::value_type& DAG<T>::Node::value() const noexcept
	{
		return graph_.values_[index_];
	}

	template<typename T>
	typename DAG<T>::value_type& DAG<T>::Node::value() noexcept
	{
		return graph_.values_[index_];
	}

	template<typename T>
	typename DAG<T>::Node& DAG<T>::Node::operator=(value_type val)
	{
		graph_.values_[index_] = val;
		return *this;
	}

	template<typename T>
	template<bool is_const>
	DAG<T>::NodeIterator<is_const>::NodeIterator():
		graph_(nullptr)
	{}

	template<typename T>
	template<bool is_const>
	DAG<T>::NodeIterator<is_const>::operator NodeIterator<true>() const noexcept
		requires(!is_const)
	{
		return DAG::NodeIterator<true>(graph_, index_);
	}

	template<typename T>
	template<bool is_const>
	typename DAG<T>::template NodeIterator<is_const>::reference DAG<T>::NodeIterator<is_const>::operator*() const noexcept
	{
		return graph_->values_[index_];
	}

	template<typename T>
	template<bool is_const>
	bool DAG<T>::NodeIterator<is_const>::operator==(const DAG<T>::NodeIterator<is_const>::self_type& other) const noexcept
	{
		return graph_ == other.graph_ && index_ == other.index_;
	}

	template<typename T>
	template<bool is_const>
	auto DAG<T>::NodeIterator<is_const>::operator<=>(const DAG<T>::NodeIterator<is_const>::self_type& other) const noexcept
	{
		if(auto cmp = graph_ <=> other.graph_; cmp != 0)
		{
			return cmp;
		}

		return index_ <=> other.index_;
	}

	template<typename T>
	template<bool is_const>
	typename DAG<T>::template NodeIterator<is_const>::self_type& DAG<T>::NodeIterator<is_const>::operator++() noexcept
	{
		++index_;
		return *this;
	}

	template<typename T>
	template<bool is_const>
	typename DAG<T>::template NodeIterator<is_const>::self_type& DAG<T>::NodeIterator<is_const>::operator--() noexcept
	{
		--index_;
		return *this;
	}

	template<typename T>
	template<bool is_const>
	typename DAG<T>::template NodeIterator<is_const>::self_type DAG<T>::NodeIterator<is_const>::operator++(int) noexcept
	{
		const auto temp = *this;
		++index_;
		return temp;
	}

	template<typename T>
	template<bool is_const>
	typename DAG<T>::template NodeIterator<is_const>::self_type DAG<T>::NodeIterator<is_const>::operator--(int) noexcept
	{
		const auto temp = *this;
		--index_;
		return temp;
	}

	template<typename T>
	template<bool is_const>
	typename DAG<T>::template NodeIterator<is_const>::self_type& DAG<T>::NodeIterator<is_const>::operator+=(std::size_t shift) noexcept
	{
		index_ += shift;
		return *this;
	}

	template<typename T>
	template<bool is_const>
	typename DAG<T>::template NodeIterator<is_const>::self_type& DAG<T>::NodeIterator<is_const>::operator-=(std::size_t shift) noexcept
	{
		index_ -= shift;
		return *this;
	}

	template<typename T>
	template<bool is_const>
	typename DAG<T>::template NodeIterator<is_const>::self_type DAG<T>::NodeIterator<is_const>::operator+(std::size_t shift) const noexcept
	{
		return DAG<T>::NodeIterator<is_const>::self_type(graph_, index_ + shift);
	}


	template<typename T>
	template<bool is_const>
	typename DAG<T>::template NodeIterator<is_const>::self_type DAG<T>::NodeIterator<is_const>::operator-(std::size_t shift) const noexcept
	{
		return DAG<T>::NodeIterator<is_const>::self_type(graph_, index_ - shift);
	}

	template<typename T>
	template<bool is_const>
	DAG<T>::NodeIterator<is_const>::NodeIterator(DAG<T>::NodeIterator<is_const>::graph_type graph, std::size_t index):
		graph_(graph), index_(index)
	{}

	template<typename T>
	template<bool is_const>
	typename DAG<T>::template NodeIterator<is_const>::difference_type DAG<T>::NodeIterator<is_const>::operator-(const DAG<T>::NodeIterator<is_const>::self_type& rhs) const noexcept
	{
		return index_ - rhs.index_;
	}

	template<typename T>
	template<typename V>
	typename DAG<T>::iterator DAG<T>::emplace(V&& value, const DAG::const_iterator& parent)
		requires std::is_same_v<std::remove_cvref_t<V>, T>
	{
		const std::size_t new_node_index = values_.size();
		values_.emplace_back(value);
		edges_.emplace(parent.index_, new_node_index);

		return iterator(*this, new_node_index);
	}

	template<typename T>
	template<typename V>
	typename DAG<T>::iterator DAG<T>::emplace(V&& value)
		requires std::is_same_v<std::remove_cvref_t<V>, T>
	{
		const std::size_t new_node_index = values_.size();
		values_.emplace_back(value);
		return iterator(this, new_node_index);
	}

	template<typename T>
	void DAG<T>::add_edge(const DAG::const_iterator& from, const DAG::const_iterator& to)
	{
		edges_.emplace(from.index_, to.index_);
	}

	template<typename T>
	typename DAG<T>::iterator DAG<T>::begin() noexcept
	{
		return iterator(*this, 0);
	}

	template<typename T>
	typename DAG<T>::const_iterator DAG<T>::begin() const noexcept
	{
		return const_iterator(this, 0);
	}

	template<typename T>
	typename DAG<T>::iterator DAG<T>::end() noexcept
	{
		return iterator(this, values_.size());
	}

	template<typename T>
	typename DAG<T>::const_iterator DAG<T>::end() const noexcept
	{
		return const_iterator(this, values_.size());
	}


	template<typename T>
	typename DAG<T>::reverse_iterator DAG<T>::rbegin() noexcept
	{
		return reverse_iterator(end());
	}

	template<typename T>
	typename DAG<T>::const_reverse_iterator DAG<T>::rbegin() const noexcept
	{
		return const_reverse_iterator(end());
	}

	template<typename T>
	typename DAG<T>::reverse_iterator DAG<T>::rend() noexcept
	{
		return reverse_iterator(begin());
	}

	template<typename T>
	typename DAG<T>::const_reverse_iterator DAG<T>::rend() const noexcept
	{
		return const_reverse_iterator(begin());
	}

	template<typename T>
	typename DAG<T>::const_iterator DAG<T>::cbegin() const noexcept
	{
		return DAG::const_iterator(this, 0);
	}

	template<typename T>
	typename DAG<T>::const_iterator DAG<T>::cend() const noexcept
	{
		return DAG::const_iterator(this, values_.size());
	}

	template<typename T>
	typename DAG<T>::const_reverse_iterator DAG<T>::crbegin() const noexcept
	{
		return const_reverse_iterator(cend());
	}

	template<typename T>
	typename DAG<T>::const_reverse_iterator DAG<T>::crend() const noexcept
	{
		return const_reverse_iterator(cbegin());
	}
}
#endif //HERD_COMMON_DAG_HPP
