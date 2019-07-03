#include <stdexcept>
#include <type_traits>
#include <vector>

template <typename T, typename U>
struct bigint {
	U base;
	std::vector<T> digits; // little-endian

	template <typename V>
	bigint(U base_, V num = 0u) :base(base_) {
		static_assert(std::is_unsigned<T>::value, "Digits must be of unsigned integer type");
		static_assert(std::is_unsigned<U>::value, "Base must be of unsigned integer type");
		static_assert(std::is_unsigned<V>::value, "Initial value must be of unsigned integer type");
		if (base <= 2) throw std::logic_error("base should exceed 2");
		while (num) {
			digits.push_back(num % base);
			num /= base;
		}
	}

	template <typename V>
	bigint & operator += (V add_) {
		static_assert(std::is_unsigned<V>::value, "Summand must be of unsigned integer type");
		typename std::common_type<T, V>::type add = add_;
		for (size_t i = 0; add; ++i) {
			if (i >= digits.size()) digits.resize(i+1, 0);


			// add the current digit
			typename std::common_type<T, V>::type dig = digits[i] + add % base;
			add /= base;

			// set the carry for the next digit
			add += dig / base;
			digits[i] = dig % base;
		}
		return *this;
	}

	template <typename V>
	bigint & operator *= (V mul) {
		static_assert(std::is_unsigned<V>::value, "Multiplier must be of unsigned integer type");
		bigint<T,U> ret(base, 0u);
		for (size_t i = 0; i < digits.size(); ++i) {
			typename std::common_type<T, V>::type add = mul * digits[i];
			for (size_t j = i; add; j++) {
				if (j >= ret.digits.size()) ret.digits.resize(j+1, 0);

				// add to the current digit
				typename std::common_type<T, V>::type dig = ret.digits[j] + add % base;
				add /= base;

				// set the carry for the next digit
				add += dig / base;

				ret.digits[j] = dig % base;
			}
		}
		return *this = ret;
	}
};
