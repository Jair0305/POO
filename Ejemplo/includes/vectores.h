#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

void inicializadorVector(int *v, int tope, int valorinicial)
{
    int i;
    for(i=0;i<tope;i++)
    {
        v[i]=valorinicial;
    }
}

void mostrarVector(int*v, int tope)
{
    int i;
    for(i=0;i<tope;i++)
        cout<<v[i]<<endl;
}

#endif // VECTORES_H_INCLUDED
