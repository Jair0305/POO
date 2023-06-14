class Punto
{
 private:
 int x;
 int y;
 public:
 Punto();
 Punto(int a, int b);
 ~Punto();
 double operator * (Punto &p);
 void mostrar();
};
