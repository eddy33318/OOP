#include "Canvas.h"
#include <stdio.h>
#include <math.h>

Canvas::Canvas(int width, int height)
{
    this -> width = width;
    this -> height = height;
    data = new char *[height];
    for (int i = 0; i < height; ++i)
    {
        data[i] = new char[width];
    }
    Clear();
}

Canvas::~Canvas()
{
    for (int i = 0; i < height; ++i)
    {
        delete[] data[i];
    }
    delete[] data;
}

bool Canvas::IsInBounds(int x, int y)
{
    return (x >= 0 && x < width && y >= 0 && y < height);
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) 
 { 
     int cx = 0; 
     int cy = ray; 
     int d = 1 - ray; 
     while (cx <= cy) 
     { 
         SetPoint(x + cx, y + cy, ch); 
         SetPoint(x + cy, y + cx, ch); 
         SetPoint(x - cx, y + cy, ch); 
         SetPoint(x - cy, y + cx, ch); 
         SetPoint(x - cx, y - cy, ch); 
         SetPoint(x - cy, y - cx, ch); 
         SetPoint(x + cx, y - cy, ch); 
         SetPoint(x + cy, y - cx, ch); 
         if (d < 0) 
         { 
             d += 2 * cx + 3; 
         } 
         else 
         { 
             d += 2 * (cx - cy) + 5; 
             cy--; 
         } 
         cx++; 
     } 
 }

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = y - ray; i <= y + ray; i++)
    {
        for (int j = x - ray; j <= x + ray; j++)
        {
            if (IsInBounds(j, i) && ((j - x) * (j - x) + (i - y) * (i - y)) <= (ray * ray))
            {
                data[i][j] = ch;
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; i++)
    {
        for (int j = left; j <= right; j++)
        {
            if (i == top || i == bottom || j == left || j == right)
            {
                if (IsInBounds(j, i))
                {
                    data[i][j] = ch;
                }
            }
        }
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; ++i)
    {
        for (int j = left; j <= right; ++j)
        {
            if (IsInBounds(j, i))
            {
                data[i][j] = ch;
            }
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (IsInBounds(x, y))
    {
        data[y][x] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2)
    {
        SetPoint(x1, y1, ch);
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void Canvas::Clear()
{
    for(int i = 0; i < height; i++)
     for(int j = 0; j < width; j++)
      data[i][j] = ' ';
}

void Canvas::Print()
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
      printf("%c ", data[i][j]);
      printf("\n");
    }
}