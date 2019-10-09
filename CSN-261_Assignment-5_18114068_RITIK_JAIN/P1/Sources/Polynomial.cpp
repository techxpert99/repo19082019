/**
 * @file Polynomial.cpp
 * @date 17/09/2019
 * @author Ritik Jain
 * @brief Definitions file for Polynomial.h
 */

#include "Polynomial.h"

asn5::Polynomial::Polynomial(const unsigned int t, const unsigned int* index, const double *coeff)
{
    unsigned int j;

    for(j = 0; j < t; j++)
    {

        if(!coeff[j])
        continue;

        if(index[j]>n)
        n = index[j];

        Key k(index[j],coeff[j]);
        this->coeff.insert(k);
    }
};

asn5::Polynomial::Polynomial(const unsigned  int n, const double *coeff)
{
    this->n = n;

    unsigned int j;
    
    for(j=0; j <= n; j++)
    {
        if(!coeff[j])
        continue;

        Key k(j, coeff[j]);
        this->coeff.insert(k);
    }
}

asn5::Polynomial::Polynomial()
{
    n = 0;
}

void asn5::Polynomial::set(const unsigned int index, const double coeff)
{

    Key __coeff (index,coeff);
    unordered_set<Key, KeyHash, KeyComparator> :: iterator _coeff;

    _coeff = this->coeff.find(__coeff);

    if(_coeff==this->coeff.end())
    {
        if(coeff)
        this->coeff.insert(__coeff);
    }
    else
    {
        if(coeff)
        _coeff->coeff = coeff;
        else
        this->coeff.erase(_coeff);
    }

    if(index>n)
    n = index;
}

double asn5::Polynomial::get(unsigned int index)
{
    if(index>n)
    return 0.0;

    Key search(index,0);
    unordered_set<Key, KeyHash, KeyComparator> :: iterator _coeff;

    _coeff = coeff.find(search);

    if(_coeff==coeff.end())
    return 0.0;
    else
    return _coeff->coeff;
    
}

unsigned int asn5::Polynomial::degree()
{
    return n;
}

void asn5::Polynomial::add(Polynomial &poly)
{

    double *v2 = poly.get();
    double *v1 = get();
    unsigned int n1 = n, n2 = poly.n;

    unsigned int j=0;

    if(n1>n2)
    {
        for(; j <= n2; j++)
            set(j,v1[j]+v2[j]);
    }
    else
    {
        for(; j <= n1; j++ )
            set(j,v1[j]+v2[j]);

        for(j=n1+1; j <= n2; j++)
            set(j,v2[j]);

        n = poly.n;
    }

    delete [] v1;
    delete [] v2;

}

void asn5::Polynomial::mul(Polynomial &poly)
{
    unsigned int i,j;
    unsigned int c;
    unsigned int deg = n + poly.n;

    double *v1 = get();
    double *v2 = poly.get();
    double *v3 = new double[n+poly.n+1];

    for(i=0; i <= deg; i++)
    v3[i] = 0;

    for(i = 0; i <= n; i ++)
    for(j = 0; j <= poly.n; j ++ )
    v3[i+j] += v1[i] * v2[j];

    n = deg;

    for(i=0; i <= n; i++)
    set(i, v3[i]);

    delete [] v1;
    delete [] v2;
    delete [] v3;
}

double* asn5::Polynomial::get()
{
    double *poly = new double[n+1];

    int j;
    for(j=0; j<= n; j++)
    poly[j] = get(j);

    return poly;
}