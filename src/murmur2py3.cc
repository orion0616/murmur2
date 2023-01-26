#include <Python.h>
#include <numpy/arrayobject.h>
#include <stdint.h>
#include <sstream>
#include <string>
#include "../include/MurmurHash2.h"

static char module_docstring[] = "This module provides murmur_64a.";
static char murmur64a_docstring[] = "This function that is given a key returns 64bit unsined integer";

static PyObject *murmur2py3_murmur64a(PyObject *self, PyObject *args);

static PyMethodDef module_methods[] = {
    {"murmur64a", murmur2py3_murmur64a, METH_VARARGS, murmur64a_docstring},
    {NULL, NULL, 0, NULL}
};


static PyObject* murmur2py3_murmur64a(PyObject* self, PyObject* args){
        const void* key = NULL;
        int len;
        uint64_t seed,hashvalue;
        if(!PyArg_ParseTuple(args,"sil",&key,&len,&seed))
                return NULL;
        hashvalue = MurmurHash64A(key,len,seed);
        return Py_BuildValue("k",hashvalue);
}

static struct PyModuleDef Murmur2py3 =
        {
                PyModuleDef_HEAD_INIT,
                "murmur2py3", /* name of module */
                "usage: murmur2py3.murmur64a(String, StringLength, SEED)\n", /* module documentation, may be NULL */
                -1,   /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
                module_methods
        };

PyMODINIT_FUNC PyInit_murmur2py3(void)
{
    return PyModule_Create(&Murmur2py3);
}