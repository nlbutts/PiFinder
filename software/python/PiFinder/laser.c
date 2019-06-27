#include <Python.h>

static char module_docstring[] =
    "This module provides an interface for the PiFinder library.";
static char get_distance_docstring[] =
    "Get a distance reading";

static PyObject *init(PyObject *self, PyObject *args);
static PyObject *get_distance(PyObject *self, PyObject *args);

static PyMethodDef module_methods[] = {
    {"init", core_get_distance, METH_VARARGS, get_distance_docstring},
    {"get_distance", core_get_distance, METH_VARARGS, get_distance_docstring},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef PiFinderMethods = {
    PyModuleDef_HEAD_INIT,
    "laser",   /* name of module */
    module_docstring, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods,
};

PyMODINIT_FUNC PyInit_laser(void)
{
    return PyModule_Create(&PiFinderMethods);
}

static PyObject *init(PyObject *self, PyObject *args)
{
    /* Parse the input tuple */
    if (!PyArg_ParseTuple(args, ""))
        return NULL;

    int distance = 0;

    /* Build the output tuple */
    PyObject *ret = Py_BuildValue("i", distance);
    return ret;
}

static PyObject *get_distance(PyObject *self, PyObject *args)
{
    /* Parse the input tuple */
    if (!PyArg_ParseTuple(args, ""))
        return NULL;

    int distance = 42;

    /* Build the output tuple */
    PyObject *ret = Py_BuildValue("i", distance);
    return ret;
}