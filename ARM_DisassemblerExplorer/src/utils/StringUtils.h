/**
 ******************************************************************************
 * @addtogroup StringUtils
 * @{
 * @file    StringUtils
 * @author  Samuel Martel
 * @brief   Header for the StringUtils module.
 *
 * @date 7/23/2020 9:35:39 AM
 *
 ******************************************************************************
 */
#ifndef _StringUtils
#define _StringUtils

/*****************************************************************************/
/* Includes */
#include <algorithm>
#include <array>
#include <string>
#include <string_view>
#include <vector>


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
