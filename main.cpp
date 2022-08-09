#include <iostream>
#include <cmath>

class Figure{
public:
    virtual double Perimeter() const = 0; //pure virtual function
    virtual double FigureSquare() const = 0; //pure virtual function
};

/*class Square: public Figure{
public:
    Square():
    side{1}{}

    explicit Square(double side_length):
    side{side_length}{}

    double GetSide() const {return side;}

    double Perimeter() const override;
    double FigureSquare() const override;

private:
    double side;
};

double Square::Perimeter() const{
    return side * 4;
}

double Square::FigureSquare() const{
    return side * side;
}*/

class Rhombus: public Figure{
public:
    Rhombus():
    side{1}, angle{3.14/2}{}

    Rhombus(double side_length, double angle_value):
    side{side_length}, angle{angle_value}{}

    double GetSide() const {return side;}

    double Perimeter() const override;
    double FigureSquare() const override;

private:
    double side;
    double angle;
};

double Rhombus::Perimeter() const{
    return side * 4;
}

double Rhombus::FigureSquare() const{
    return side * side * std::sin(angle);
}

class Square final: public Rhombus{
public:
    Square(){}

    explicit Square(double side):
    Rhombus(side, 3.14/2){}

    double Perimeter() const final;
    double FigureSquare() const final;
};

/*class NewSquare: public Square{
    double Perimeter() const override;
    double FigureSquare() const override;
};

double NewSquare::Perimeter() const{
    return 4;
}

double NewSquare::FigureSquare() const{
    return 2;
}*/

/*class NewNewSquare: public Square{
     double Perimeter() const override;
    double FigureSquare() const override;
};

double NewNewSquare::Perimeter() const{
    return 4;
}

double NewNewSquare::FigureSquare() const{
    return 2;
}*/

double Square::Perimeter() const{
    return GetSide() * 4;
}

double Square::FigureSquare() const{
    return GetSide() * GetSide();
}

class Rectangle: public Figure{
public:
    Rectangle():
    first_side{1},
    second_side{1}{}

    explicit Rectangle(double first_side_length, double second_side_length):
    first_side{first_side_length},
    second_side{second_side_length}{}

    double GetFirstSide() const {return first_side;}
    double GetSecondSide() const {return second_side;}

    double Perimeter() const override;
    double FigureSquare() const override;
private:
    double first_side;
    double second_side;
};

double Rectangle::Perimeter() const{
    return 2 * (first_side + second_side);
}

double Rectangle::FigureSquare() const{
    return first_side * second_side;
}

int main(){
    Square s{2};
    Rectangle r{2,3};

    std::cout<<"Square: "<<s.Perimeter()<<" "<<s.FigureSquare()<<std::endl;
    std::cout<<"Rectangle: "<<r.Perimeter()<<" "<<r.FigureSquare()<<std::endl;

    //Figure* f1 = new Square{3};
    Figure* f1 = new Rhombus{3, 0.75};
    Figure* f2 = new Rectangle{4,5};
    Figure* f3 = new Square{3};

    std::cout<<f1->Perimeter()<<" "<<f1->FigureSquare()<<std::endl;
    std::cout<<f2->Perimeter()<<" "<<f2->FigureSquare()<<std::endl;
    std::cout<<f3->Perimeter()<<" "<<f3->FigureSquare()<<std::endl;

    return 0;
}