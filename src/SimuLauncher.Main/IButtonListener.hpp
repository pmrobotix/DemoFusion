/*
 * IButtonListener.hpp
 *
 *  Created on: 30 janv. 2016
 *      Author: pmx
 */

#ifndef SIMULAUNCHER_MAIN_IBUTTONLISTENER_HPP_
#define SIMULAUNCHER_MAIN_IBUTTONLISTENER_HPP_

#include <iostream>

class IButtonListener
{
public:

	virtual void leftButtonPressed() = 0;
	virtual void rightButtonPressed() = 0;
	virtual void leftButtonPressedAndRelease() = 0;
	virtual void rightButtonPressedAndRelease() = 0;

	/*!
	 * \brief Destructeur de la classe.
	 */
	virtual inline ~ IButtonListener()
	{
	}

protected:
	/*!
	 * \brief Constructeur de la classe.
	 */
	IButtonListener()
	{
	}

};

#endif /* SIMULAUNCHER_MAIN_IBUTTONLISTENER_HPP_ */
