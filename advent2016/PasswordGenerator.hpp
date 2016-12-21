#include "../advent2016/HashInputGenerator.hpp"

namespace Advent2016
{
	class PasswordGenerator
	{
	public:
        PasswordGenerator() :
            m_password()
		{
		}

		void generate(const char *doorId)
		{
		}

		const char *getPassword() const
		{
			return m_password.c_str();
		}

	private:

	private:
		std::string m_password;
	};
}
