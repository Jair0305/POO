class pila
{
private:
  char[100]tamanho;
  int *ptr;

public:
  void meter(char* tamanho);
  void sacar(void);
  char pilavacia(pila p);
  char pilallena(pila p);
};
