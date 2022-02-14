#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double point_distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
int main()
{
    int points_number;
    double x_points[1000];
    double y_points[1000];
    printf("Input number of points(min - 2): ");
    scanf("%d", &points_number);
    if(points_number >=2)
    {
        printf("Input %d points in format x y('enter' after each point):\n", points_number);
        double x, y, point1_best_x, point1_best_y, point2_best_x, point2_best_y, min_distance;
        for(int i = 0; i < points_number; i++)
        {
            scanf("%lf %lf", &x, &y);
            x_points[i] = x;
            y_points[i] = y;
        }
        min_distance = point_distance(x_points[0], y_points[0], x_points[1], y_points[1]);
        for(int i = 0; i < points_number; i++)
            for(int j = 0; j < points_number; j++)
        {
            if(i != j)
            {
                if(min_distance > point_distance(x_points[i], y_points[i], x_points[j], y_points[j]))
                {
                    min_distance = point_distance(x_points[i], y_points[i], x_points[j], y_points[j]);
                    point1_best_x = x_points[i];
                    point1_best_y = y_points[i];
                    point2_best_x = x_points[j];
                    point2_best_y = y_points[j];
                }
            }
        }
        printf("The shortest distance is %.3lf\n", min_distance);
        printf("The best distance between points: (%.3lf, %.3lf) and (%.3lf, %.3lf)", point1_best_x, point1_best_y, point2_best_x, point2_best_y);

    }
    else
    {
        printf("Invalid input, at least 2 points");
    }
}
