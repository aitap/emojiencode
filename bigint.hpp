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
	bigint & operator += (V add) {
		static_assert(std::is_unsigned<V>::value, "Summand must be of unsigned integer type");
		T carry = 0;
		for (size_t i = 0; add || carry; ++i) {
			if (i >= digits.size()) digits.resize(i+1, 0);

			// add the current digit
			digits[i] += add % base + carry;
			add /= base;

			// set the carry for the next digit
			carry = digits[i] / base;
			digits[i] %= base;
		}
		return *this;
	}

	template <typename V>
	bigint & operator *= (V mul) {
		static_assert(std::is_unsigned<V>::value, "Multiplier must be of unsigned integer type");
		bigint<T,U> ret(base, 0u);
		for (size_t i = 0; i < digits.size(); ++i) {
			T add = mul * digits[i], carry = 0;
			for (size_t j = i; add || carry; j++) {
				if (j >= ret.digits.size()) ret.digits.resize(j+1, 0);

				// add to the current digit
				ret.digits[j] += add % base + carry;
				add /= base;

				// set the carry for the next digit
				carry = digits[j] / base;
				ret.digits[j] %= base;
			}
		}
		return *this = ret;
	}
};
