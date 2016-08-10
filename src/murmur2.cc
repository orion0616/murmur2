#include <Python.h>
#include <numpy/arrayobject.h>
#include <stdint.h>
#include <sstream>
#include <string>
#include "../include/MurmurHash2.h"

static char module_docstring[] = "This module provides murmur_64a.";
static char murmur64a_docstring[] = "This function that is given a key returns 64bit unsined integer";

static PyObject *murmur_murmur64a(PyObject *self, PyObject *args);

static PyMethodDef module_methods[] = {
    {"murmur64a", murmur_murmur64a, METH_VARARGS, murmur64a_docstring},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initmurmur(void){
    PyObject *m = Py_InitModule3("murmur", module_methods, module_docstring);
    if(m==NULL)
        return;
    import_array();
}

std::string uint64_to_string(uint64_t value ) {
    std::ostringstream os;
    os << value;
    return os.str();
}

static PyObject* murmur_murmur64a(PyObject* self, PyObject* args){
        const void* key = NULL;
        int len;
        uint64_t seed,hashvalue;
        if(!PyArg_ParseTuple(args,"sil",&key,&len,&seed))
                return NULL;
        hashvalue = MurmurHash64A(key,len,seed);
        return Py_BuildValue("k",hashvalue);
}

