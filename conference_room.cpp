#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip> // for precision setting
using namespace std;

typedef struct	s_complex
{
	double	x;
	double	y;
}	t_complex;

ostream& operator<<(ostream& os, const t_complex& z) // ostream& - output stream reference...
{ //... with predefined object, namely structure (also via reference)
    os << z.x << " " << z.y;
    return os;
    // returning output stream allow to chain all << signs so each of them knows where to print data
}

t_complex	ft_get_coordinates(double X, double Y, vector<t_complex> plan)
{
	t_complex	res;
	double	room_diag;
	double	plan_diag;
	double	scale;
	double	angle_x;
	double	angle_y;
	double	angle;
	double	x;
	double	y;
	double	denom;

	room_diag = sqrt(X * X + Y * Y); //sqrt - square root; pow - power(exponentiation)
	plan_diag = sqrt(pow(plan[1].x - plan[0].x, 2) + pow(plan[1].y - plan[0].y, 2));
	scale = plan_diag / room_diag;
	angle_x = plan[1].x - plan[0].x;
	angle_y = plan[1].y - plan[0].y;
	angle = atan2(angle_y, angle_x); //2-argument arctagent (angle calculation)
					 //for example, if x-axis = 1, and y-axis = 1,
					 //the angle is 45 degrees.
					 //anlge is directly proportional y and
					 //inversely proportional x 
	x = plan[0].x;
	y = plan[0].y;
	denom = 1 - scale * cos(angle);
	res.x = (x - scale * (x * cos(angle) + y * sin(angle))) / denom;
	res.y = (y + scale * (x * sin(angle) - y * cos(angle))) / denom;
	return (res);
}

int	main(void)
{
	vector<t_complex>	plan(4);
	double	tmp_x;
	double	tmp_y;
	t_complex	res;
	double	X;
	double	Y;
	int	i;
	cin >> X >> Y;
	i = 0;
	while (i < 4)
	{
		cin >> tmp_x >> tmp_y;
		plan[i].x = tmp_x;
		plan[i].y = tmp_y;
		i++;
	}
	res = ft_get_coordinates(X, Y, plan);
	cout << res << setprecision(4) << endl; // setprecision controls number of digits
						// to display for float-pointing number.
						// When used as is it sets total digits,
						// and rounds digits. 
						// When used with fixed or scientific
						// it sets digits after the decimal point,
						// and trails zeros, like 5.000000
						// Scientific also adds e+02-like end
						// should be unset explicitly with
						// cout.unsetf(ios::fixed)
}
