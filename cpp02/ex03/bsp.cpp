/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:04:37 by escura            #+#    #+#             */
/*   Updated: 2024/08/05 14:29:36 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed area(Point const a, Point const b, Point const c)
{
    Fixed x1 = a.getX();
    Fixed y1 = a.getY();

    Fixed x2 = b.getX();
    Fixed y2 = b.getY();

    Fixed x3 = c.getX();
    Fixed y3 = c.getY();

    Fixed area = (x1 * (y2-y3) + x2 * (y3 - y1) + x3 * (y1- y2)) / 2;
    if(area < 0)
        area = area * -1;

    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed A = area(a, b, c);

    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);

    return (A == A1 + A2 + A3);
}