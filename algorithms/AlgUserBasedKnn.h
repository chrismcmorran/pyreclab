#ifndef __ALG_USER_BASED_KNN_H__
#define __ALG_USER_BASED_KNN_H__

#include "RecSysAlgorithm.h"

#include <string>
#include <stdexcept>


class AlgUserBasedKnn
      : public RecSysAlgorithm< boost::numeric::ublas::mapped_matrix<double, boost::numeric::ublas::row_major> >
{
public:

   AlgUserBasedKnn( DataReader& dreader,
                    int userpos = 0,
                    int itempos = 1,
                    int ratingpos = 2 );

   int train();

   int train( size_t k, std::string& similarity );

   double predict( std::string& userId, std::string& itemId )
   throw( std::invalid_argument );

   double predict( size_t userrow, size_t itemcol );

private:

   size_t m_knn;

   std::map<std::string, double> m_meanRatingByUser;

   SparseMatrix< boost::numeric::ublas::mapped_matrix<double, boost::numeric::ublas::row_major> > m_simMatrix;

};

#endif // __ALG_USER_BASED_KNN_H__

