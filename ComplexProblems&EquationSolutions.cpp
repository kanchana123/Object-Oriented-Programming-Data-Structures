// Kanchan Nannavare
// CSC-152 - HW4
// Complex numbers and equation solutions

#include <iostream>     // for cin, cout
#include <vector>       // for vector in Menu class
#include <iomanip>      // for setprecision
#include <cmath>        // sqrt() for equation functions
#include <string>       // operator <<

using namespace std;

///////////////////////////
// MENU CLASS DEFINITION //
///////////////////////////

class Menu
{
private:
    vector<string> options;
    
public:
    Menu(string options_array[], int n)
    {
        for (int i = 0; i < n; i++)
            options.push_back(options_array[i]);
    }
    
    void display_options()
    {
        cout << "<<<< OPTIONS >>>>" << endl;
        
        for (int i = 0; i < options.size(); i++)
            cout << (i + 1) << ": " << options[i] << endl;
    }
    
    int get_input()
    {
        cout << "Please enter an option (1-" << options.size() << "): ";
        int option;
        cin >> option;
        return option;
    }
};

//////////////////////
/// Complex Number ///
//////////////////////

class ComplexNumber
{
public:
    
    friend ostream & operator<<(ostream & output, ComplexNumber & z)
    {
        if (z.imaginary < 0)
        {
            output << setprecision(5) << z.real << "-" << setprecision(5) << z.imaginary * (-1) << "i";
        }
        else if(z.imaginary == 0)
        {
            output << setprecision(5) << z.real;
        }
        else
        {
            output << setprecision(5) << z.real << "+" << setprecision(5) << z.imaginary << "i";
        }
        return output;
    }
    
    static ComplexNumber prompt()
    {
        double real, imaginary;
        cout << "Please enter a real part of the number: ";
        cin >> real;
        cout << "Please enter an imaginary part of the number: ";
        cin >> imaginary;
        return ComplexNumber(real, imaginary);
    }
    
private:
    double real, imaginary;
    
public:
    ComplexNumber()
    {
    }
    
    ComplexNumber(double another_real)
    {
        real = another_real;
        imaginary = 0;
    }
    
    ComplexNumber(double another_real, double another_imaginary)
    {
        real = another_real;
        imaginary = another_imaginary;
    }
    
    ComplexNumber negate()
    {
        return ComplexNumber(-real, -imaginary);
    }
    
    ComplexNumber add(ComplexNumber other_complex_no)
    {
        double sum_real = this->real + other_complex_no.real;
        double sum_imaginary = this->imaginary + other_complex_no.imaginary;
        return ComplexNumber(sum_real, sum_imaginary);
    }
    
    ComplexNumber substract(ComplexNumber other_complex_no)
    {
        return this->add(other_complex_no.negate());
    }
    
    ComplexNumber multiply(ComplexNumber other_complex_no)
    {
        double product_real = (real * other_complex_no.real) + (imaginary * other_complex_no.imaginary)*(-1);
        double product_imaginary = (real * other_complex_no.imaginary) + (imaginary * other_complex_no.real);
        
        return ComplexNumber(product_real, product_imaginary);
    }
    
};

ComplexNumber operator+(ComplexNumber z1, ComplexNumber z2)
{
    return z1.add(z2);
}

ComplexNumber operator-(ComplexNumber z1, ComplexNumber z2)
{
    return z1.substract(z2);
}

ComplexNumber operator*(ComplexNumber z1, ComplexNumber z2)
{
    return z1.multiply(z2);
}



///////////////////////////////////
/// Equation Solution Functions ///
///////////////////////////////////

double a, b, c;         // Global variables

void get_coefficients()
{
    cout << "Please enter the coefficients (a, b, c) for equation ax^2 + bx + c: ";
    double a1, b1, c1;
    cin >> a1 >> b1 >> c1;
    
    a = a1;
    b = b1;
    c = c1;
}

double b2_4ac()
{
    return (b * b) - (4 * a * c);
}

double first_part()
{
    return (b * (-1))/(2*a);
}

double second_part()
{
    return sqrt(b2_4ac())/(2*a);
}

double non_complex_solution1()                  // non complex solution 1
{
    return first_part() + second_part();
}

double non_complex_solution2()                  // non complex solution 2
{
    return first_part() - second_part();
}

double solution_imaginary()                     // complex number imaginary part
{
    return sqrt(b2_4ac()*(-1))/(2*a);
}

ComplexNumber complex_solution1()            // complex number solution 1
{
    return ComplexNumber(first_part(), solution_imaginary());
}

ComplexNumber complex_solution2()            // complex number solution 2
{
    return ComplexNumber(first_part(), -solution_imaginary());
}

ComplexNumber check_complex(ComplexNumber sol_z)
{
    
    ComplexNumber a1(a);                // conversion of non complex number into complex number
    ComplexNumber b1(b);
    ComplexNumber c1(c);
    
    ComplexNumber answer;

    answer = (a1 * sol_z * sol_z) + (b1 * sol_z) + c1;
    
    return answer;
}

double check_non_complex(double sol)
{
    return (a * sol * sol) + (b * sol) + c;
}

////////////
/// Main ///
////////////

int main()
{
    string options[] = {"Enter a complex number z1",
        "Enter a complex number z2",
        "Calculate z1 + z2",
        "Calculate z1 - z2",
        "Calculate z1 * z2",
        "Solve a quadratic equation with real coefficients",
        "Quit"};
    
    const int NO_OF_OPTIONS = 7;
    Menu menu = Menu(options, NO_OF_OPTIONS);
    int option;
    
    ComplexNumber z1(-1,2), z2(3,4);
    
    do {
        menu.display_options();
        option = menu.get_input();
        
        if (option == 1)
        {
            z1 = ComplexNumber::prompt();
        }
        else if (option == 2)
        {
            z2 = ComplexNumber::prompt();
        }
        else if (option == 3)
        {
            ComplexNumber sum = z1+z2;
            cout << "(" << z1 << ") + (" << z2 << ") = " << sum << endl;
        }
        else if (option == 4)
        {
            ComplexNumber substraction = z1-z2;
            cout << "(" << z1 << ") - (" << z2 << ") = " << substraction << endl;
        }
        else if (option == 5)
        {
            ComplexNumber multiplication = z1*z2;
            cout << "(" << z1 << ") * (" << z2 << ") = " << multiplication << endl;
        }
        else if (option == 6)
        {
            get_coefficients();
            if (b2_4ac() < 0)
            {
                ComplexNumber sol1 = complex_solution1();
                ComplexNumber sol2 = complex_solution2();
                
                cout << "Solutions: " << sol1 << ", " << sol2 << endl;
                
                ComplexNumber check_sol1 = check_complex(complex_solution1());
                ComplexNumber check_sol2 = check_complex(complex_solution2());
                
                cout << "Evaluating the equation of x = " << setprecision(5) << sol1 << " gives " << setprecision(5) << check_sol1 << endl;
                
                cout << "Evaluating the equation of x = " << setprecision(5) << sol2 << " gives " << setprecision(5) << check_sol2 << endl;
            }
            else
            {
                cout << "Solutions: " << non_complex_solution1() << ", " << non_complex_solution2() << endl;
                ComplexNumber check_sol1 = check_non_complex(non_complex_solution1());
                ComplexNumber check_sol2 = check_non_complex(non_complex_solution2());
                
                cout << "Evaluating the equation of x = " << setprecision(5)<< non_complex_solution1() << " gives " << setprecision(5) << check_sol1 << endl;
                
                cout << "Evaluating the equation of x = " << setprecision(5)<< non_complex_solution2() << " gives " << setprecision(5) << check_sol2 << endl;
            }
        }
    
    } while (option != NO_OF_OPTIONS);

    return 0;
}
