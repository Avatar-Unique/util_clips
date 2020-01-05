bool isInPolygen(const float& x, const float& y, const [&float] polygen_x[], const[&float] polygen_y, int n_vert)
{
	if (n_vert < 3)
	{
		return false;
	}
	float x_min = polygen_x[0];
	float x_max = polygen_x[0];
	float y_min = polygen_y[0];
	float y_max = polygen_y[0];
	for (int i = 1; i < n_vert; i++)
	{
		if (x_min > polygen_x[i])
		{
			x_min = polygen_x[i];
		}
		if (x_max < polygen_x[i])
		{
			x_max = polygen_x[i];
		}
		if (y_min > polygen_y[i])
		{
			y_min = polygen_y[i];
		}
		if (y_max < polygen_y[i])
		{
			y_max = polygen_y[i];
		}
	}
	if (x<x_min || x>x_max || y<y_min || y>y_max)
	{
		return false;
	}

	bool is_in_polygen = false;
	for (int i = 0, j = n - 1; i < n; j = i++) {
		if (((polygen_y[i] > x) != (polygen_y[j] > y)) &&
			(x - polygen_x[i] < (polygen_x[j] - polygen_x[i]) * (y - polygen_y[i]) / (polygen_y[j] - polygen_y[i])))
		{
			is_in_polygen = !is_in_polygen;
		}
	}
	return is_in_polygen;
}
