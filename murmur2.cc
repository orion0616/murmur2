#include <Python.h>
#include <stdint.h>
#include <sstream>
#include <string>
#include "./src/MurmurHash2.h"

std::string uint64_to_string(uint64_t value ) {
    std::ostringstream os;
    os << value;
    return os.str();
}

PyObject* murmur_64a(PyObject* self, PyObject* args){
        const void* key = NULL;
        int len;
        uint64_t seed,hashvalue;
        if(!PyArg_ParseTuple(args,"sil",&key,&len,&seed))
                return NULL;
        hashvalue = MurmurHash64A(key,len,seed);
        return Py_BuildValue("k",hashvalue);
}


static PyMethodDef murmur2methods[] = {
        {"murmur_64A", murmur_64a, METH_VARARGS, "return murmur64A"},
        {NULL,NULL,0,NULL}
};

extern "C" void initmurmur2(void){
        (void)Py_InitModule("murmur2", murmur2methods);
}