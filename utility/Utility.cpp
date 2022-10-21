#include "conio.h"
#include "Utility.h"

#include <iostream>

namespace Utility
{
	// ------------------------------------------------------------------------------------------------------------------------------

	std::string GetNumberTyped()
	{
		std::cout << "-> ";

		std::string numberTyped;

		// --------------------------------------------------------------------------------------------------------------

		do
		{
			char key = _getch();

			// Let the user to type only one key between 1 and 4.
			if (key >= '1' && key <= '4' && numberTyped.size() <= 0)
			{
				numberTyped += key;
				std::cout << key;
			}

			// If the key pressed is "delete".
			if (key == 8)
			{
				// If the input is not empty.
				if (!numberTyped.empty())
				{
					// Delete the last character and put the cursor back from 1 character in the console.
					numberTyped.pop_back();
					std::cout << "\b \b";
				}
			}

			// If the key pressed is "enter".
			if (key == 13)
			{
				if (numberTyped.empty())
				{
					// The input is empty, so ask the user to type something again.
					std::cout << std::endl << "No value entered. Please enter a valid one" << std::endl;
					std::cout << "-> ";
				}

				else
				{
					break;
				}
			}

		} while (true);

		// --------------------------------------------------------------------------------------------------------------

		return numberTyped;
	}

	// ------------------------------------------------------------------------------------------------------------------------------

}