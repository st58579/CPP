// Sem_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "ArrayList.h"
#include "Point3D.h"
#include "BubbleSort.h"

int main()
{
    ArrayList* a = new ArrayList(1);
    IComparable* p1 = new Point3D(1, 2, 2);
    IComparable* p2 = new Point3D(3, 6, 3);
    IComparable* p3 = new Point3D(2, 2, 1);
    IComparable* p4 = new Point3D(14, 3, 1);
    IComparable* p5 = new Point3D(12, 1, 1);
    a->add(p1);
    a->add(p2);
    a->add(p3);
    a->add(p4);
    a->add(p5);
    BubbleSort sort = BubbleSort();
    for (size_t i = 0; i < a->getCount(); i++)
    {
        std::cout << dynamic_cast<Point3D*>(a->get(i))->toString() << std::endl;
    }
    std::cout << std::endl << "------------------" << std::endl;
    sort.sort(a);
    for (size_t i = 0; i < a->getCount(); i++)
    {
        std::cout << dynamic_cast<Point3D*>(a->get(i))->toString() << std::endl;
    }
    
}

