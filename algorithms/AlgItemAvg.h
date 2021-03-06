#ifndef __ALG_ITEM_AVERAGE_H__
#define __ALG_ITEM_AVERAGE_H__

#include "RecSysAlgorithm.h"

#include <string>
#include <map>


class AlgItemAvg
      : public RecSysAlgorithm< boost::numeric::ublas::mapped_matrix<double, boost::numeric::ublas::column_major> >
{
public:

   AlgItemAvg( DataReader& dreader,
               int userpos = 0,
               int itempos = 1,
               int ratingpos = 2 );

   ~AlgItemAvg();

   int train();

   double predict( std::string& userId, std::string& itemId );

   double predict( size_t userrow, size_t itemcol );
 
private:

   double* m_meanRatingByItemCol;

};

#endif // __ALG_ITEM_AVERAGE_H__

