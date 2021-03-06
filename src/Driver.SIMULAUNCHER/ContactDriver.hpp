#ifndef SIMULAUNCHER_CONTACTDRIVER_HPP_
#define SIMULAUNCHER_CONTACTDRIVER_HPP_

#include "../Common/Action.Driver/AContactDriver.hpp"
#include "../Log/LoggerFactory.hpp"


using namespace std;


class ContactDriver: public AContactDriver
{
private:

	/*!
	 * \brief Retourne le \ref Logger associé à la classe \ref ContactDriver(SIMULAUNCHER).
	 */
	static inline const logs::Logger & logger()
	{
		static const logs::Logger & instance = logs::LoggerFactory::logger("ContactDriver.SIMULAUNCHER");
		return instance;
	}


public:


	/*!
	 * \brief Constructor.
	 */
	ContactDriver();

	/*!
	 * \brief Destructor.
	 */
	virtual ~ContactDriver();

	virtual int pressed();

};

#endif
