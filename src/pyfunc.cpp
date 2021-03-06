/*
 * Use of this source code is governed by the MIT License (MIT).
 * See the LICENSE file for details.
 *
 * Copyright (c) 2016 Artem Korzhimanov <korzhimanov.artem@gmail.com>
 */

/**
 * \file pyfunc.cpp
 * \brief The source file which implements the methods of the PyFunc class
 * \author Artem Korzhimanov
 * \copyright The MIT License (MIT)
 */

#include "include/pyfunc.h"

PyFunc::PyFunc() {}

PyFunc::PyFunc(PyObject* pObj) { function = pObj; }

PyFunc::PyFunc(const PyFunc& pyfunc) { function = pyfunc.function; }

PyFunc::~PyFunc() {
  if (function != NULL) Py_DECREF(function);
}

double PyFunc::call(double arg1) {
  PyObject* ArgsTuple = PyTuple_New(1);
  PyTuple_SetItem(ArgsTuple, 0, PyFloat_FromDouble(arg1));

  PyObject* Result = PyObject_CallObject(function, ArgsTuple);

  double ret = PyFloat_AsDouble(Result);

  Py_DECREF(ArgsTuple);
  Py_DECREF(Result);

  return ret;
}

double PyFunc::call(double arg1, double arg2) {
  PyObject* ArgsTuple = PyTuple_New(2);
  PyTuple_SetItem(ArgsTuple, 0, PyFloat_FromDouble(arg1));
  PyTuple_SetItem(ArgsTuple, 1, PyFloat_FromDouble(arg2));

  PyObject* Result = PyObject_CallObject(function, ArgsTuple);

  double ret = PyFloat_AsDouble(Result);

  Py_DECREF(ArgsTuple);
  Py_DECREF(Result);

  return ret;
}

double PyFunc::call(double arg1, double arg2, double arg3) {
  PyObject* ArgsTuple = PyTuple_New(3);
  PyTuple_SetItem(ArgsTuple, 0, PyFloat_FromDouble(arg1));
  PyTuple_SetItem(ArgsTuple, 1, PyFloat_FromDouble(arg2));
  PyTuple_SetItem(ArgsTuple, 2, PyFloat_FromDouble(arg3));

  PyObject* Result = PyObject_CallObject(function, ArgsTuple);

  double ret = PyFloat_AsDouble(Result);

  Py_DECREF(ArgsTuple);
  Py_DECREF(Result);

  return ret;
}
