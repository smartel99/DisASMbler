/******************************************************************************
 * @file StringUtils
 * @author Samuel Martel
 * @date 2020/07/27
 * @brief
 ******************************************************************************
 * Copyright (C) 2020  Samuel Martel - Pascal-Emmanuel Lachance
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *****************************************************************************/
#ifndef _StringUtils
#define _StringUtils

/*****************************************************************************/
/* Includes */
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <charconv>


/*****************************************************************************/
/* Exported defines */

/*****************************************************************************/
/* Exported macro */

/*****************************************************************************/
/* Exported types */
/************************************************************************/
/* Is type std::vector                                                  */
/************************************************************************/
template<typename>
struct is_std_vector : std::false_type
{
};

template<typename T, typename A>
struct is_std_vector<std::vector<T, A>> : std::true_type
{
};
/************************************************************************/

/************************************************************************/
/* Is type std::array                                                   */
/************************************************************************/
template<typename T>
struct is_std_array : std::false_type
{
};

template<size_t size>
struct is_std_array<std::array<char, size>> : std::true_type
{
};

template<size_t size>
struct is_std_array<std::array<uint8_t, size>> : std::true_type
{
};
class StringUtils
{
public:
    template<class T, class U = char>
    static std::string ToString(T val)
    {
        if constexpr (is_std_vector<T>::value == true || is_std_array<T>::value == true)
        {
            std::stringstream ss;
            for (size_t i = 0; i < val.size(); i++)
            {
                ss << val.at(i);
            }

            return ss.str();
        }
        else if constexpr (std::is_convertible<T, int>::value == true)
        {
            std::stringstream ss;
            ss << val;
            return ss.str();
        }
        else
        {
            return "";
        }
    }

    template<class T = int>
    static T ToVal(const std::string& str)
    {
        T var;
        std::from_chars(str.data(), str.data() + str.size(), var);

        return var;
    }

    static std::string MakeUniqueIdString(const std::string& label, const void* uniqueId)
    {
        return label + "##" + ToString(uniqueId);
    }

    static std::string RemoveExtraWhitespaces(const std::string_view inputString)
    {
        /* Copy each character from the input string into the output string, unless it's
         * repeating space */
        /* From : https://stackoverflow.com/a/35302029 */
        std::string outputString;

        /* clang-format off */
        std::unique_copy(inputString.begin(),
                         inputString.end(),
                         std::back_insert_iterator<std::string>(outputString),
                         [](char a, char b)
                         {
                            return std::isspace(a) && std::isspace(b);
                         });
        /* clang-format on */

        return outputString;
    }
};



/* Have a wonderful day :) */
#endif /* _StringUtils */
/**
 * @}
 */
/****** END OF FILE ******/
