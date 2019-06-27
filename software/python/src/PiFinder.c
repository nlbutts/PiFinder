#include <Python.h>

static char module_docstring[] =
    "This module provides an interface for the PiFinder library.";
static char get_distance_docstring[] =
    "Get a distance reading";

static PyObject *core_get_distance(PyObject *self, PyObject *args);

static PyMethodDef module_methods[] = {
    {"get_distance", core_get_distance, METH_VARARGS, get_distance_docstring},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef PiFinderMethods = {
    PyModuleDef_HEAD_INIT,
    "PiFinder",   /* name of module */
    module_docstring, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods,
};

PyMODINIT_FUNC PyInit_PiFinder(void)
{
    return PyModule_Create(&PiFinderMethods);

}

static PyObject *core_get_distance(PyObject *self, PyObject *args)
{
    /* Parse the input tuple */
    if (!PyArg_ParseTuple(args, ""))
        return NULL;

    int distance = 42;

    /* Build the output tuple */
    PyObject *ret = Py_BuildValue("i", distance);
    return ret;
}