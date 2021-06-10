#include <stdexcept>

namespace FooLang
{
class InvalidLeftHandAssignmentException : public std::logic_error
{
public:
    InvalidLeftHandAssignmentException() : std::logic_error("Invalid left-hand side in assignment.") {}
};
} // namespace FooLang
