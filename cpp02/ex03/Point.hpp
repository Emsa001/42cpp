/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:32:34 by escura            #+#    #+#             */
/*   Updated: 2024/08/05 14:44:33 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
    private:
        const Fixed _x;
        const Fixed _y;
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &point);

        ~Point();

        Fixed getX() const;
        Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
