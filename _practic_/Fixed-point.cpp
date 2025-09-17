# include <iostream>
# include <cmath>

int main()
{
	float	f_number;
	int		fixed_point;
	int		fractional;

	fractional = 8;

	f_number =  7.325;
	
	fixed_point = roundf(f_number * (1 << fractional));
	std::cout << "fixed_point --> " << fixed_point << std::endl;

	std::cout << "from fixed-point to float --> " << (float(fixed_point) / (1 << fractional)) << std::endl;
}