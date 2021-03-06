#ifndef __PY_CONJUGATE_GRADIENT_H__
#define __PY_CONJUGATE_GRADIENT_H__

#include <Python.h> // This header was set at the first place to avoid warnings

#include "AlgIFAlsConjugateGradient.h"
#include "DataReader.h"
#include "MAE.h"
#include "RMSE.h"

class PyIFAlsConjugateGradient
{
public:

   PyObject_HEAD
   DataReader* m_trainingReader;
   AlgIFAlsConjugateGradient* m_recAlgorithm;
   MAE m_mae;
   RMSE m_rmse;
};

PyTypeObject* IFAlsConjugateGradient_getTypeObject();
PyObject* IFAlsConjugateGradient_new( PyTypeObject* type, PyObject* args, PyObject* kwdict );
void IFAlsConjugateGradient_dealloc( PyIFAlsConjugateGradient* self );
PyObject* IFAlsConjugateGradient_train( PyIFAlsConjugateGradient* self, PyObject* args, PyObject* kwdict );
PyObject* IFAlsConjugateGradient_recommend( PyIFAlsConjugateGradient* self, PyObject* args, PyObject* kwdict );
PyObject* IFAlsConjugateGradient_testrec( PyIFAlsConjugateGradient* self, PyObject* args, PyObject* kwdict );

#endif // __PY_CONJUGATE_GRADIENT_H__

