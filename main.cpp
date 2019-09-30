/* Блистунова Валерия М8О-201Б
--------------------------------
Лабораторная работа №2. Вариант №11
Создать класс vector3D, задаваемый тройкой координат.
Обязательно должны быть реализованы: операции сложения и вычитания векторов,
векторное произведение векторов, скалярное произведение векторов, умножения на скаляр,
сравнение векторов на совпадение,вычисление длины вектора, сравнение длины векторов, вычисление угла между векторами.
Операции сложения, вычитания, сравнения (на равенство, больше и меньше) должны быть выполнены в виде перегрузки операторов. 
Необходимо реализовать пользовательский литерал для работы с константами типа vector3D.
*/

#include<iostream>
#include<cmath>
using namespace std;

class vector
{
    public:
        double x, y, z;
        vector operator+(vector b);
        vector operator-(vector b);
        vector Vector_mult(vector a, vector b);
        double Scalar_mult(vector a, vector b);
        vector Mult(vector a, double c);
        double Lenght(vector a);
        double Angle(vector a, vector b);
        bool operator==(vector b);
        void Display(vector c);
};

vector vector::operator+(vector b){
    vector t;
    t.x=x+b.x;
    t.y=y+b.y;
    t.z=z+b.z;
    return t;
}
vector vector::operator-(vector b){
    vector t;
    t.x=x-b.x;
    t.y=y-b.y;
    t.z=z-b.z;
    return t;
}
vector Vector_mult(vector a, vector b){
    vector t;
    t.x=a.y*b.z-a.z*b.y;
    t.y=-(a.x*b.z-a.z*b.x);
    t.z=a.x*b.y-a.y*b.x;
    return t;
}
double Scalar_mult(vector a, vector b){
    double t;
    t=a.x*b.x+a.y*b.y+a.z*b.z;
    return t;
}
vector Mult(vector a, double c){
    a.x*=c;
    a.y*=c;
    a.z*=c;
    return a;
}
double Lenght(vector a){
    double l;
    l=sqrt(pow((a.x),2)+pow((a.y),2)+pow((a.z),2));
    return l;
}

double Angle(vector a, vector b){
    double t;
    t=(Scalar_mult(a,b)/(Lenght(a)*Lenght(b)));
    return t;
}
bool vector::operator==(vector b){
    return((x==b.x) && (y==b.y) && (z==b.z));
}
void Display(vector a){
    cout << "(" << a.x << ";" << a.y << ";" << a.z << ")" << endl;
}
void Menu(){
    cout << "Введите число от 1 до 10 или 0 для действий: " << endl << 
						"1. Распечатать меню" << endl <<
						"2. Сложение векторов" << endl <<
						"3. Вычитание векторов" << endl <<
						"4. Векторное произведение векторов" << endl << 
						"5. Скалярное произведение векторов" << endl <<
						"6. Умножение вектора на скаляр" << endl <<
                        "7. Сравнение векторов" << endl <<
                        "8. Вычисление длины вектора" << endl <<
                        "9. Сравнение длин векторов" << endl <<
                        "10. Вычисление угла между векторами" << endl <<
						"11. Задать координаты векторов" << endl <<
                        "0. Выход из программы" << endl;
}

int main(){
    vector a,b,c,d;
    int user_command=11;
    double t,r;
    cout << "Работа с геометрическими векторами" << endl;
    Menu();
    for(;;){
        switch(user_command){
            case 1:
                Menu();
                break;
            case 2:
                c=a+b;
                Display(c);
                break;
            case 3:
                c=a-b;
                Display(c);
                break;
            case 4:
                c=Vector_mult(a, b);
                Display(c);
                break;
            case 5:
                t=Scalar_mult(a,b);
                cout << "" << t << endl;
                break;
            case 6:
                cout << "Введите число, на которое нужно умножить векторы ";
                cin >> t;
                c=Mult(a, t);
                d=Mult(b, t);
                Display(c);
                Display(d);
                break;
            case 7:
                if(a == b)
                    cout << "Векторы равны" << endl;
                else cout << "Векторы различны" << endl;    
                break;
            case 8:
                t=Lenght(a);
                r=Lenght(b);
                cout << "Длина первого вектора: " << t << endl;
                cout << "Длина второго вектора: " << r << endl;
                break;
            case 9:
                t=Lenght(a);
                r=Lenght(b);
                if(t<r)
                    cout << "Длина второго вектора больше, чем первого" << endl;
                else if (t>r)
                    cout << "Длина первого вектора больше, чем второго" << endl;
                else cout << "Длины векторов равны" << endl;
                break;
            case 10:
                t=Angle(a,b);
                cout << "Косинус угла между векторами равен " << t << endl;
                break;
            case 11:
                cout << "Задайте новые координаты первого вектора: ";
                cin >> a.x >> a.y >> a.z;
                cout << "Задайте новые координаты второго вектора: ";
                cin >> b.x >> b.y >> b.z;
                break;
            case 0:
                exit(0);
            default:
                cerr << "Нет такого пункта меню" << endl;
                break;
        }
        cout << endl << "Введите пункт меню: ";
        cin >> user_command; 
    }
    return 0;
 }