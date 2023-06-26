// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception> // std::exception

// Custom exception class derived from std::exception
class MyException : public std::exception
{
public:
    const char* what() const noexcept override // Overrides what() function
    {
		return "Something went wrong - Custom, My Exception"; // Returns error message
	}
};

bool do_even_more_custom_application_logic()
{
    throw std::exception("Something went wrong - Even More Custom Application Logic"); // Throws exception

    std::cout << "Running Even More Custom Application Logic." << std::endl; // Displays success message

    return true;
}

void do_custom_application_logic()
{
    
    std::cout << "Running Custom Application Logic." << std::endl; // Displays starting message

    try
    {
        // Calls do_even_more_custom_application_logic()
        do_even_more_custom_application_logic();
        std::cout << "Even More Custom Application Logic Succeeded." << std::endl; // Displays success message
    }
    catch (const std::exception& ex)
    {
        std::cout << "An Error Occurred: " << ex.what() << std::endl; // Displays error message
    }

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main

    throw MyException(); // Throws custom exception

    std::cout << "Leaving Custom Application Logic." << std::endl; // Displays leaving message

}

float divide(float num, float den)
{

    // Check if denominator is zero
    if (den == 0)
    {
        // Throws exception if denominator is zero
		throw std::exception("Cannot divide by zero");
	}
    // Returns quotient if denominator is not zero
    return (num / den);
}

void do_division() noexcept
{

    std::cout << "Running Do Division." << std::endl; // Displays starting message
    try
    {
        float numerator = 10.0f;
        float denominator = 0;

        auto result = divide(numerator, denominator); // Calls divide() function
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl; // Displays result

    }
    catch (const std::exception& ex)
    {
		std::cout << "An Error Occurred: " << ex.what() << std::endl; // Displays error message
	}
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    try
    {
        // TODO: Create exception handlers that catch (in this order):
        //  your custom exception
        //  std::exception
        //  uncaught exception 
        //  that wraps the whole main function, and displays a message to the console.
        do_division();
        do_custom_application_logic();

    }
    catch (const MyException& ex)
    {
        std::cout << "An Error Occurred: " << ex.what() << std::endl; // Displays error message
	}
	catch (const std::exception& ex)
	{
		std::cout << "An Error Occurred: " << ex.what() << std::endl; // Displays error message
    }
    catch (...)
    {
		std::cout << "An Error Occurred: " << std::endl; // Displays error message
	}
    
	std::cout << "Quitting." << std::endl; // Displays quitting message

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu