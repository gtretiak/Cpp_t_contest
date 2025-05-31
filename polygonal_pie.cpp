#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef struct s_point
{
	double	x;
	double	y;
	s_point(double x_val = 0, double y_val = 0) : x(x_val), y(y_val){} // initializing to 0
	bool operator<(const s_point& other) const {
		return y < other.y;
	} // overloading < operator telling how to compare structures's certain members
	  // const prevent from modifying (read-only)
	  // true if the current struct's certain member less than other struct's same member
}	t_point;

vector<t_point>	ft_find_intersections(const vector<t_point>& polygon, double mid)
{
	vector<t_point>	intersections;
	t_point	point1;
	t_point	point2;
	int	n;
	int	j;
	double	t;
	double	y;

	n = polygon.size();
	for (int i = 0; i < n; i++)
	{
		j = (i + 1) % n; //vertex or point of intersection
		point1 = polygon[i];
		point2 = polygon[j];
		if (point1.x == mid && point2.x == mid)
			continue ;
		if ((point1.x <= mid && point2.x >= mid) // if it's true that means that it's crossed...
			|| (point1.x >= mid && point2.x <= mid)) //... by the vertical line
		{
			if (point1.x == point2.x)
				continue ;
			t = (mid - point1.x) / (point2.x - point1.x); // This is a linear interpolation
			y = point1.y + t * (point2.y - point1.y); // to find the crossing point
			intersections.emplace_back(mid, y); // then we add it to the list
			// emplace constructs object in-place, whereas push copy and move
			// also it might take two parameters directly,
			// whereas push_back only in {}
		}
	}
	sort(intersections.begin(), intersections.end()); // we sort the list by y-coordinate
/*	cout << "For x = " << mid << ", intersections: "; // debugging message
	for (const auto& p : intersections) cout << "(" << p.x << ", " << p.y << ") ";
	cout << endl;*/
	return (intersections);
}

double	ft_calculate_area(vector<t_point>& polygon)
{
	double	area;
	int	n;
	int	j;

	area = 0.0;
	n = polygon.size();
	for (int i = 0; i < n; i++)
	{
		j = (i + 1) % n;
		area += polygon[i].x * polygon[j].y - polygon[i].y * polygon[j].x;
		// this is a Gauss's area formula to calculate the area of any simple polygon
		// simple means with no intersecting edges
	}
	return (abs(area) / 2.0); // absolute value (non-negative)
}

double	ft_calculate_left(const vector<t_point>& polygon, double mid)
{
	vector<t_point>	left_polygon;
	vector<t_point>	intersections;

	intersections = ft_find_intersections(polygon, mid);
	if (intersections.empty()) // The entire polygon is either left or right of the line.
	{
		if (polygon[0].x < mid) // This means the polygon is on the left side entirely
			return (ft_calculate_area(const_cast<vector<t_point>&>(polygon)));
		// const_cast removes const from the parameter to call non-const function
		else
			return (0.0);
	}
	for (const auto& p : polygon) // auto extracts type automatically
				      // with const it prevents modification 
	{
		if (p.x <= mid)
			left_polygon.push_back(p);// we collect all original vertices left of the line
	}
	for (const auto& p : intersections)
		left_polygon.push_back(p); // then we add to the list intersection points
/*	cout << "Left polygon points for x = " << mid << ":\n"; // debugging message
	for (const auto& p : left_polygon) cout << "(" << p.x << ", " << p.y << ")\n";*/
	return (ft_calculate_area(left_polygon));
}

double	ft_find_dividing_x(const vector<t_point> polygon, double target_area, double precision = 1e-6)
{
	double	minX;
	double	maxX;
	double	mid;
	double	left_area;
	double	curr_diff;
	double	best_diff;
	double	best_mid;
	
	minX = polygon[0].x;
	maxX = polygon[0].x;
	best_diff = INFINITY;
	for (const auto& p : polygon)
	{
		minX = min(minX, p.x); // it founds the minimum x and maximum x 
		maxX = max(maxX, p.x); // so we can know bounds of polygon on x-axis coordinate
	}
	best_mid = minX; // safety measure to return at least minX
	while (maxX - minX > precision) // it might not be exactly the middle
					// but close to it according to precision
					// In our example, 1e-6 = 0.000001
					// the more concise precision, the more effort to compute
	{
		mid = (minX + maxX) / 2.0; // mid is exactly the middle of a polygon's bounds
		left_area = ft_calculate_left(polygon, mid);// at each midpoint we calculate left
		curr_diff = abs(left_area - target_area);//that's the absolute difference
		if (curr_diff < precision)
			return (mid);
		if (curr_diff < best_diff)
		{
			best_diff = curr_diff;
			best_mid = mid;
		}
		if (left_area < target_area)//Here we narrow the the options using binary search
			minX = mid;// left is less, so we need to move mid right
		else // left is bigger, so let's move mid left
			maxX = mid;
	}
	return (best_mid);
}

int	main(void)
{
	int	n;
	double	x;
	double	y;
	vector<t_point>	polygon;
	double	area;
	double	res;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		polygon.emplace_back(x, y); // definition coordinates of each vertex
	}
	area = ft_calculate_area(polygon);
	res = ft_find_dividing_x(polygon, area / 2.0);
	cout << fixed << setprecision(9) << res << endl; // it means 9 digits after dot
	return (0);
}
