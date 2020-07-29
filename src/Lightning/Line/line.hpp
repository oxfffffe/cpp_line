#pragma once

#include <ostream>
#include <istream>
#include <string.h> ///< strcat, strcmp, ...
#include "src/defines.hpp" ///< unsigned short -> s16
#include "src/Lightning/namespace/lightning.hpp"

/*!
 * @brief Line represents class to work
 * with text strings.
 */
class lightning::Line
{
public:
	Line(){};

	/*!
	 * @brief Constructor copies @param to
	 * private field "str".
	 */
	Line
	(const char*);

	~Line();

	/*!
	 * @brief overloading default output stream operator.
	 * @return std::basic_ostream<char>&
	 */
	friend std::ostream&
	operator<<(std::ostream&, const Line&) noexcept;

	/*!
	 * @brief overloading default input stream operator.
	 * @return std::basic_istream<char>&
	 */
	friend std::istream&
	operator>>(std::istream&, Line&) noexcept;

	/*!
	 * @return result of concatenation.
	 * this->str with @param
	 */
	char*
	operator+(const Line&) noexcept;

	/*!
	 * @return result of concatenation.
	 * this->str with @param
	 */
	char*
	operator+(const char*) noexcept;

	bool
	operator==(const Line&) noexcept;

	bool
	operator==(const char*) noexcept;

	bool
	operator!=(const Line&) noexcept;

	bool
	operator!=(const char*) noexcept;

	/*!
	 * @brief concatenate this->str with Line.str
	 * and save result to this->str.
	 */
	void
	operator+=(const Line&) noexcept;

	/*!
	 * @brief concatenate this->str with char array
	 * and save result to this->str.
	 */
	void
	operator+=(const char*) noexcept;

	char*
	to_upper() noexcept;

	char*
	to_lower() noexcept;

	char*
	reverse() noexcept;

	/*!
	 * @brief to_char_array method needed
	 * for the Regex class,
	 * which accepts char* as a @param
	 * in Regex::match_exists.
	 * @return this->str
	 */
	char*
	to_char_array() noexcept;

	/*!
	 * @brief replace method cannot get
	 * FIRST @param == SECOND @param
	 * to avoid waste of resources by replacing
	 * text with itself.
	 */
	char*
	replace(const char* __restrict__,
	        const char* __restrict__) noexcept;

	char*
	cut(const char*) noexcept;

	s16
	length() noexcept;

	/*!
	 * @return empty string
	 */
	const char*
	clear() noexcept;

private:
	char* str;
};

