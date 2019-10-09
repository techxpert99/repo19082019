/**
 * @file Polynomial.h
 * @date 17/09/2019
 * @author Ritik Jain
 * @brief Interface file for Polynomial.cpp
 */

#ifndef POLYNOMIAL_H

#define POLYNOMIAL_H

#include <unordered_set>
#include <iterator>

using namespace std;

/**
 * @date 17/08/2019
 * @author Ritik Jain
 * @brief Assignment #5
 */
namespace asn5
{
    /**
     * @date 17/09/2019
     * @author Ritik Jain
     * @brief Used to store Polynomials
     */
    class Polynomial
    {
        private:
        
        /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Stores coefficient and its index for the unordered set
         */
        struct Key
        {
            public:
            mutable double coeff;
            unsigned int index;
            Key(unsigned int _index, int _coeff) : index(_index) , coeff(_coeff)
            {

            }
        };

        /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Hash function for the set
         */
        struct KeyHash
        {
            size_t operator () (const Key &key) const
            {
                return hash<int>()(key.index);
            }
        };

        /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Comparator for the set
         */
        struct KeyComparator
        {
            public :
            bool operator () (const Key &k1, const Key &k2) const
            {
                return (k1.index==k2.index);
            }
        };

        //Stores the coefficients (non-zero) and their indices
        unordered_set <Key, KeyHash, KeyComparator> coeff;

        //The degree of the polynomial
        unsigned int n;

        
        public:
        
        /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Constructs a polynomial with the given coefficients (non-zero) and their indices
         * @param t  The number of non-zero coefficients in the polynomial
         * @param index  The indices of non-zero coefficients
         * @param coeff  The non-zero coefficients
         */
        Polynomial(unsigned const int t, unsigned const int *index, const  double *coeff);

        /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Constructs a polynomial with the given coefficients (all) and the degree
         * @param n  The degree of the polynomial
         * @param coeff  The coefficients of the polynomial
         */
        Polynomial(unsigned const int n, const double *coeff);

         /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Constructs an empty polynomial
         */
        Polynomial();

        /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Sets a coefficient of the polynomial
         * @param index  The index of the coefficient
         * @param coeff  The coefficient
         */
        void set(unsigned const int index, const double coeff);

        /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Gets a coefficient of the polynomial
         * @param index  The index of the coefficient
         * @return The coefficient
         */
        double get(unsigned const int index);

        /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Adds the given polynomial to this polynomial
         * @param poly  The polynomial to be added
         */
        void add(Polynomial &poly);

        /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Multiplies the given polynomial to this polynomial
         * @param poly  The polynomial to be multiplied with
         */
        void mul(Polynomial &poly);

        /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Gets the degree of this polynomial
         * @return The degree
         */
        unsigned int degree();

        /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Gets this polynomial as a bundle of double
         * @return The polynomial (double[])
         */
        double* get();

        /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Overloaded Operator '+' : Adds the 2nd polynomial to the 1st polynomial
         */
        Polynomial& operator + (Polynomial &p2)
        {
            add(p2);
            return *this;
        }

        /**
         * @date 17/09/2019
         * @author Ritik Jain
         * @brief Overloaded Operator '*' : Multiplies the 2nd polynomial to the 1st polynomial
         */
        Polynomial& operator * (Polynomial &p2)
        {
            mul(p2);
            return *this;
        }

        ~Polynomial()
        {
            coeff.clear();
        }
    };

}

#endif //POLYNOMIAL_H
