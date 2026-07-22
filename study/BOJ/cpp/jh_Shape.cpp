#include <iostream>
using namespace std;

class Rectangle
{
    private:
    int width, height, size;
    public:
    Rectangle()
    {
        
    }
    void R_data_in()
    {
        cin >> width >> height;
    }
    void R_data_out()
    {
        size = width * height;
        cout << width  << " " << height << " " << size << endl;
    }

};
class Triangle
{
    private:
    int width, height;
    double size;
    public:
    Triangle()
    {
       
    }
    void T_data_in()
    {
        cin >> width >> height;
    }
    void T_data_out()
    {   size = width * height;
        size /= 2;
        cout << width << " " << height << " " << size << endl;
    }
};
class Shape 
{
    private:
    Rectangle mem;
    Triangle ber;
    public:
    Shape()
    {
        
    }
    void Shape_num1()
    {
        mem.R_data_in();
    }
    void Shape_num2()
    {
        ber.T_data_in();
    }
    void Shape_num3()
    {
        mem.R_data_out();
    }
    void Shape_num4()
    {
        ber.T_data_out();
    }
};
int main()
{
    int menu;
    Shape num;
    while (true)
    {
        cin >> menu;
        if (menu == 0)
        {
            break;
        }
        else if (menu == 1)
        {
            num.Shape_num1();
        }
        else if (menu == 2)
        {
            num.Shape_num2();
        }
        else if (menu == 3)
        {
            num.Shape_num3();
        }
        else if (menu == 4)
        {
            num.Shape_num4();
        }
    }
}