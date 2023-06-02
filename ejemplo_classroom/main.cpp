#include <iostream>

using namespace std;

class Manipulator
{
    public:
        virtual ~Manipulator(){};
        virtual void downClick() = 0;
        virtual void drag() = 0;
        virtual void upClick() = 0;
};

class LineManipulator : public Manipulator
{
    public:
        LineManipulator(){};
        ~LineManipulator(){};

        void downClick()
        {
            cout << "Line down click" << endl;
        }
        void drag()
        {
            cout << "Line drag" << endl;
        }
        void upClick()
        {
            cout << "Line up click" << endl;
        }
};

class TextManipulator : public Manipulator
{
    public:
        TextManipulator(){};
        ~TextManipulator(){};

    void downClick()
    {
        cout << "Text down click" << endl;
    }
    void drag()
    {
        cout << "Text drag" << endl;
    }
    void upClick()
    {
        cout << "Text up click" << endl;
    }

};

class Figure
{
    public:
        Figure(){};
        ~Figure()
        {
            delete _manipulator;
        };

        Manipulator* getManipulator()
        {
            // If _manipulator is NULL, calls the createManipulator method.
            if (_manipulator == nullptr) {
                _manipulator = createManipulator();
            }
            return _manipulator;
        }

        void downClick() { _manipulator->downClick(); }
        void drag() { _manipulator->drag(); }
        void upClick() { _manipulator->upClick(); }

    protected:
        virtual Manipulator* createManipulator() = 0;
    private:
        Manipulator* _manipulator = nullptr;
};

class LineFigure : public Figure
{
    public:
        LineFigure(){};
        ~LineFigure(){};

        Manipulator* createManipulator()
        {
            return new LineManipulator();
        }
};

class TextFigure : public Figure
{
    public:
        TextFigure(){};
        ~TextFigure(){};

        Manipulator* createManipulator()
        {
            return new TextManipulator();
        }
};


int main()
{

    Figure* t = new TextFigure();
    Figure* l = new LineFigure();


    t->getManipulator();
    t->upClick();
    t->downClick();
    t->drag();

    l->getManipulator();
    l->upClick();
    l->downClick();
    l->drag();

    delete l;
    delete t;


    return 0;
}